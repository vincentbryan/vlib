//
// Created by vincent on 18-4-3.
//

#pragma once

namespace vlib{

    template <typename T>
    class ObjectPool{

        template <typename ...Args>
        using constructor = std::function<std::shared_ptr<T>(Args...)>;

    private:
        multimap<string, shared_ptr<T>> m_objects;
        int m_max_size = 0;
        bool m_need_clear = false;

    public:
        ObjectPool(int max_size) : m_max_size(max_size){
            m_need_clear = false;
        }

        ~ObjectPool(){
            m_need_clear = true;
        }

        template <typename ...Args>
        void Init(int num, Args... args){

            if(num <= 0 || num > m_max_size)
                throw std::logic_error("Object number out of range");

            auto constructor_name = typeid(constructor<Args...>).name();
            bool need_clear = m_need_clear;

            for(int i = 0; i < num; i++){
                m_objects.emplace(constructor_name,
                                  std::shared_ptr<T>(new T((args)...), [constructor_name, need_clear, this](T* t){
                                     deletePtr(constructor_name, need_clear, t);
                                  }));
            }

        };

        void deletePtr(const string& constructor_name, bool need_clear, T* t){
            if (need_clear){
                delete t;
            }
            else{
                m_objects.emplace(constructor_name, std::shared_ptr<T>(t, [constructor_name, need_clear, this](T* t){
                    deletePtr(constructor_name, need_clear, t);
                }));
            }
            return;
        }

        template <typename ...Args>
        std::shared_ptr<T> Get(){

            auto constructor_name = typeid(constructor<Args...>).name();
            auto range = m_objects.equal_range(constructor_name);

            for(auto it = range.first; it != range.second; ++it){
                auto ptr = it->second;
                m_objects.erase(it);
                return ptr;
            }

            return nullptr;
        }

        int Size(){
            return m_objects.size();
        }

    };

}
