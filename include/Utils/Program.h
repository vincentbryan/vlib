//
// Created by vincent on 18-5-4.
//

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <atomic>
#include <cassert>
#include "Timer.h"

using namespace std;

namespace vlib{
    class Program {

    public:

        static shared_ptr<Program> Instance;

        explicit Program(int rate = 25) : mRate(rate){
            assert(mRate > 0);
            mFinishFlag = false;
        };

        virtual ~Program(){};

        void SetRate(size_t rate);

        size_t GetRate() const;

        void SetArg(int argc, char * argv[]);

        int main();

        void Finish();


    protected:
        virtual void OnStart() = 0;

        virtual void OnRun() = 0;

        virtual void OnFinish() = 0;

        int argc;
        vector<string> argv;

    private:

        size_t mRate;

        atomic_bool mFinishFlag;

        Timer mTimer;
    };
}
