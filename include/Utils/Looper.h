// Created by vincent on 18-5-8.
//

#pragma once

#include <stdatomic.h>
#include <cassert>
#include "Timer.h"

namespace vlib{
    class Looper{

    private:
        int mRate;

        atomic_bool mFinishFlag;

        Timer mTimer;

    public:
        Looper(int rate = 25) : mRate(rate){
            assert(mRate > 0);
            mFinishFlag = false;
        }

        void SetRate(const int rate);

        int GetRate() const;

        virtual void OnStart() = 0;

        virtual void OnRun() = 0

        virtual void OnFinish() = 0;

        void Finish();

        void Loop();

    };
}