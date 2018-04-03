#pragma once
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <list>

using namespace std;

namespace vlib{

    template <typename T>
    class SyncQueue{
    private:

        mutex m_mutex;
        condition_variable m_notFull;
        condition_variable m_notEmpty;
        list<T> m_queue;
        int m_queueSize;

        bool m_needStop;

        bool NotFull() const {
            bool full = m_queue.size() == m_queueSize;
            if(full){
                cout << "Sync Queue is Full, thread " << this_thread::get_id() << " is waiting..." << endl;
            }
            return !full;
        }

        bool NotEmpty() const {
            bool empty = m_queueSize == 0;
            if(empty){
                cout << "Sync Queue is Empty, thread " << this_thread::get_id() << " is waiting..." << endl;
            }
            return !empty;
        }

        template <typename F>
        void Add(F&& f){
            unique_lock<mutex> lock_(m_mutex);
            m_notFull.wait(lock_, [this]()->bool{
                return NotFull() || m_needStop;
            });

            if(m_needStop) return;

            m_queue.emplace_back(forward<F>(f));
            m_notEmpty.notify_one();
        }

    public:

        SyncQueue(int queueSize):m_queueSize(queueSize), m_needStop(false){};


        void Put(const T& t){
            Add(t);
        }

        void Put(T&& t){
            Add(forward<T>(t));
        }

        void Take(T& t){
            unique_lock<mutex> lock_(m_mutex);
            m_notEmpty.wait(lock_, [this]()->bool{
                return NotEmpty() || m_needStop;
            });

            if(m_needStop) return;

            t = m_queue.front();
            m_queue.pop_front();
            m_notFull.notify_one();
        }

        void Take(list<T>& list){
            unique_lock<mutex> lock(m_mutex);
            m_notEmpty.wait(lock, [this]()->bool{
                return NotEmpty() || m_needStop;
            });
            if(m_needStop) return;
            list = move(m_queue);
            m_notEmpty.notify_one();
        }

        bool Empty(){
            lock_guard<mutex> lock_guard(m_mutex);
            return m_queue.empty();
        }

        bool Full(){
            lock_guard<mutex> lock_guard(m_mutex);
            return m_queue.size() == m_queueSize;
        }

        size_t Size(){
            lock_guard<mutex> lock_guard(m_mutex);
            return m_queue.size();
        }

        void Stop(){
            {
                lock_guard<mutex> lock_guard(m_mutex);
                m_needStop = true;
            }

            m_notFull.notify_all();
            m_notEmpty.notify_all();
        }

    };
}
