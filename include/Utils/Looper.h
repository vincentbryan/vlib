// Created by vincent on 18-5-8.
//

#pragma once

#include <cassert>
#include <atomic>
#include <thread>
#include "Timer.h"

namespace vlib{
    class Looper{

    private:
        int mRate;

        std::atomic_bool mFinishFlag;

        Timer mTimer;

        std::thread* th;

    public:
        explicit Looper(int rate = 25) : mRate(rate){
            assert(mRate > 0);
            mFinishFlag = false;
            th = nullptr;
        }

        virtual ~Looper(){};

        void SetRate(const int rate);

        int GetRate() const;

        virtual void OnStart() = 0;

        virtual void OnRun() = 0;

        virtual void OnFinish() = 0;

        void Finish();

        void Loop();
        
        void Start();

        bool Joinable();

        void Join();

    };
}