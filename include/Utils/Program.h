//
// Created by vincent on 18-5-4.
//

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>
#include "Timer.h"
#include "Looper.h"

using namespace std;

namespace vlib{
    class Program : public Looper{

    public:

        static shared_ptr<Program> Instance;

        explicit Program(int rate = 25) : Looper(rate){};

        virtual ~Program(){};

        void SetArg(int argc, char * argv[]);

        int main();


    protected:

        int argc;
        vector<string> argv;
    };
}
