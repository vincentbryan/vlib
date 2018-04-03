#pragma once

namespace vlib{
    template <typename T>
    class Singleton{

    private:
        static T* instance;

        Singleton(void);
        virtual ~Singleton(void);
        Singleton(const Singleton&);
        Singleton&operator = (const Singleton)&;

    public:
        template <typename... Args>
        static T* Instance(Args&&... args){
            if(instance == nullptr){
                instance = new T(std::forward<Args>(args)...);
            }
            return instance;
        }

        static T* GetInstance(){
            if(instance == nullptr){
                throw std::logic_error("The instance has not been created yet");
            }
            return instance;
        }

        static void DestroyInstance(){
            if(instance != nullptr){
                delete instance;
                instance = nullptr;
            }
        }

    };

    template <typename T> T*
    Singleton<T>::instance = nullptr;

}
