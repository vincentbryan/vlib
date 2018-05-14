//
// Created by vincent on 18-5-8.
//


#include "Utils/Looper.h"

using namespace vlib;

void Looper::Finish(){
    mFinishFlag = true;
}

void Looper::SetRate(const int rate){
    assert(rate > 0);
    mRate = rate;
}

int Looper::GetRate() const {
    return mRate;
}

void Looper::Loop() {

    OnStart();

    while(!mFinishFlag){

        mTimer.Reset();

        OnRun();

        long sleep_time = long( 1000.0 / mRate - mTimer.ElapsedMilli());

        if(sleep_time > 0)
            mTimer.Sleep(sleep_time);
    }

    OnFinish();
}

void Looper::Start() {
    th = new std::thread(&Looper::Loop, this);
}

bool Looper::Joinable() {
    return th->joinable();
}

void Looper::Join() {
    th->join();
}

