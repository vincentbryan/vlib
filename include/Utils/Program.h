//
// Created by vincent on 18-5-4.
//

#pragma once

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

namespace vlib{
    class Program {

    public:
        explicit Program(){};

        static shared_ptr<Program> Instance;

        int main();

        void Set(int argc, char * argv[]);

        virtual ~Program(){};

    protected:
        virtual void OnStart() = 0;

        virtual void OnRun() = 0;

        virtual void OnFinish() = 0;

        int argc;
        vector<string> argv;

    };
}
