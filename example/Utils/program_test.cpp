//
// Created by vincent on 18-5-4.
//

#include "program_test.h"

VLIB_PROGRAM(program_test);


void program_test::OnStart() {
    cout << "OnStart" << endl;
}

void program_test::OnRun() {
    cout << "OnRun" << endl;
}

void program_test::OnFinish() {
    cout << "OnFinish" << endl;
}