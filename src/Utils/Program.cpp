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

    Program::Instance->Start();

    return 0;
}

void Program::SetArg(const int argc_, char* argv_ []){
    this->argc = argc_;
    for (int i = 0; i < argc_; ++i) {
        this->argv.emplace_back(argv_[i]);
    }
}


int main(int argc, char* argv []){
    Program::Instance->SetArg(argc, argv);
    Program::Instance->main();
}

