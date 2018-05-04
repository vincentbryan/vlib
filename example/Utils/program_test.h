//
// Created by vincent on 18-5-4.
//

#pragma once

#include <vlib>
#include <iostream>

using namespace std;
using namespace vlib;


class program_test : public Program{

public:
    program_test(){};

protected:
    void OnStart() override ;

    void OnRun() override ;

    void OnFinish() override ;

};

