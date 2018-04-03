//
// Created by vincent on 18-3-31.
//
#include <iostream>
#include <vlib>

using namespace std;
using namespace vlib;

int main(){

    AsyncThreadPool pool(2);
    thread th1([&pool]{
        for (int i = 0; i < 10; ++i) {
            auto th_id = this_thread::get_id();
            cout << "th1 is adding task " << i << " to SyncQueue" << endl;
            pool.AddTask([th_id]{
                cout << "Sync th1 " << th_id << " is running..." << endl;
            });
        }
    });

    thread th2([&pool]{
        for (int i = 0; i < 10; ++i) {
            auto th_id = this_thread::get_id();
            cout << "th2 is adding task " << i << " to SyncQueue" << endl;
            pool.AddTask([th_id]{
                cout << "Sync th2 " << th_id << " is running..." << endl;
            });
        }
    });

    th1.join();
    th2.join();

    this_thread::sleep_for(std::chrono::seconds(2));
    pool.Stop();
};