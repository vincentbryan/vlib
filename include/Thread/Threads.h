//
// Created by vincent on 18-3-11.
//

#pragma once

#include <thread>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
#include <atomic>

#include "macro.h"
#include "SyncQueue.hpp"

using namespace std;

namespace vlib{
/*
    template <typename Iterator, typename T>
    class ThreadPool {
    public:

        ThreadPool(vector<thread>) = delete;

        explicit ThreadPool(unsigned int num){
            threadNumber = num;
        }

        static void ForEach(Iterator, Iterator, T&, function<void(const T, T&)>);

        static void printNumber(T, int, int, int);

        void ParallelForEach(Iterator it1, Iterator it2, T& init, function<void(const T, T&)> func);

        void setThreadNumber(const unsigned int num){
            threadNumber = num;
        }

        unsigned int getThreadNumber(){
            return threadNumber;
        }

        struct accumulate_block
        {
            void operator()(Iterator first,Iterator last,T& result)
            {
                result=std::accumulate(first,last,result);
            }
        };


    private:

        unsigned int threadNumber;

    };


    template <typename Iterator, typename T>
    void ThreadPool<Iterator, T>::ForEach(Iterator it1, Iterator it2, T &result, function<void(const T, T&)> func){
        while(it1 != it2){
            func(*it1, result);
            it1++;
        }
    };

    template <typename Iterator, typename T>
    void ThreadPool<Iterator, T>::printNumber(T t, int a, int b, int c) {
        cout << t << endl;
    }


    template <typename Iterator, typename T>
    void ThreadPool<Iterator, T>::ParallelForEach(Iterator it1, Iterator it2, T& init, function<void(T, T&)> func){

        unsigned int const length = distance(it1, it2);
        if(length == 0) return ;

        unsigned int const hardware_threads = thread::hardware_concurrency();
        unsigned int const actual_threads = min(threadNumber, hardware_threads);
        unsigned int const block_size = length / actual_threads;

        vector<T>temp_result;
        temp_result.assign(actual_threads, init);

        vector<thread> threads(actual_threads-1);

        Iterator start_it = it1, end_it;

//        for(int i = 0; i < actual_threads-1; ++i){
//            advance(end_it, block_size);
////            threads[i] = thread(&ForEach, start_it, end_it, ref(temp_result[0]), func);
//            threads[i] = thread(&printNumber, 10, 0, 0, 0);
//            start_it = end_it;
//
//        }

        ForEach(start_it, it2, temp_result.back(), func);
//        for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
        cout << init << endl;
        accumulate(temp_result.begin(), temp_result.end(), &init);
        cout << init << endl;
    }
*/

    class AsyncThreadPool{

    public:

        static int MaxTaskCount;

        using Task = function<void()>;

        explicit AsyncThreadPool(int numThreads = thread::hardware_concurrency()):m_queue(MaxTaskCount){
            Start(numThreads);
        }

        ~AsyncThreadPool(){
            Stop();
        }
        void Stop(){
            call_once(m_flag, [this]{
                StopThreadGroup();
            });
        }

        void AddTask(Task&& task){
            m_queue.Put(forward<Task>(task));
        }

        void AddTask(const Task& task){
            m_queue.Put(task);
        }



    private:
        list<shared_ptr< thread>> m_threadGroup;
        SyncQueue<Task> m_queue;
        atomic_bool m_running;
        once_flag m_flag;

        void Start(int numThreads){
            m_running = true;
            for (int i = 0; i < numThreads; ++i) {
                m_threadGroup.emplace_back(make_shared<thread>(&AsyncThreadPool::RunThread, this));
            }
        }

        void RunThread(){
            while (m_running){
                list<Task> list;
                m_queue.Take(list);

                for(auto& task : list){
                    if(!m_running) return;
                    cout << this_thread::get_id() << "is executing ..." << endl;
                    task();
                }
            }
        }

        void StopThreadGroup(){
            m_queue.Stop();
            m_running = false;

            for(auto th : m_threadGroup){
                if(th) th->join();
            }

            m_threadGroup.clear();
        }
    };

    int AsyncThreadPool::MaxTaskCount = 100;


}