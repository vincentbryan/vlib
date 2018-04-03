//
// Created by vincent on 18-4-1.
//

#pragma once

#include <map>
using namespace std;

namespace vlib{
    template <typename ...Args>
    class Observer{
    private:

    public:
        Observer(){

        }
    };


    template <typename Func>
    class Subject{
    private:

        //一个模板函数
        template <typename F>
        int Assign(F&& f){
            int k = m_observerId++;
            m_observers.emplace(k, std::forward<F>(f));
            return k;
        }

        int m_observerId = 0;
        map<int, Func> m_observers;

    public:
        Subject(){};
        ~Subject(){};


        int AddObserver(Func&& f){
            return Assign(std::forward<Func>(f));
        }

        int AddObserver(const Func& f){
            return Assign(f);
        }

//        template <typename T>
//        int AddObserver(T&& t, F&& f){
//            return Assign(*t.*f);
//        }

        void RemoveObserver(int key){
            m_observers.erase(key);
        }

        template <typename ...Args>
        void Notify(Args&&... args){
            for(auto& it : m_observers){
                it.second(std::forward<Args>(args)...);
            }
        }

    };
}
