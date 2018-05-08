//
// Created by vincent on 18-5-4.
//

#include <zconf.h>
#include <csignal>
#include "Program.h"
using namespace vlib;

shared_ptr<Program>  Program::Instance = nullptr;



int Program::main(){
    if (Program::Instance == nullptr){
        cerr << "Use VLIB_PROGRAM(__PROGRAM_NAME__)" << endl;
    }

    auto OnFinishHandler = [](int n){
        cout << "Terminated..." << endl;
        Program::Instance->Finish();
    };

    signal(SIGTERM, OnFinishHandler);
    signal(SIGHUP,  OnFinishHandler);
    signal(SIGINT,  OnFinishHandler);
    signal(SIGQUIT, OnFinishHandler);
    signal(SIGKILL, OnFinishHandler);

    Program::Instance->OnStart();

    while (!mFinishFlag){

        mTimer.Reset();

        Program::Instance->OnRun();

        auto sleep_time = long ( 1000.0f / mRate - mTimer.ElapsedMicro());

        if (sleep_time > 0){
            // milliseconds
            mTimer.Sleep(sleep_time);
        }
    }

    Program::Instance->OnFinish();

    return 0;
}

void Program::SetArg(const int argc_, char* argv_ []){
    this->argc = argc_;
    for (int i = 0; i < argc_; ++i) {
        this->argv.emplace_back(argv_[i]);
    }
}

void Program::SetRate(size_t rate){
    assert(rate > 0);
    mRate = rate;
}

size_t Program::GetRate() const {
    return mRate;
}

void Program::Finish(){
    mFinishFlag = true;
}

int main(int argc, char* argv []){
    Program::Instance->SetArg(argc, argv);
    Program::Instance->main();
}

