//
// Created by vincent on 18-4-3.
//

#include <iostream>
#include <vlib>

using namespace std;
using namespace vlib;

class Test{
private:
    int x;
    double y;

public:
    Test(){};

    Test(int x_, double y_ = 0.0) : x(x_), y(y_){};

    Test(Test&& t):x(t.x){};

    Test(const Test& t) : x(t.x){};

    Test& operator = (const Test& t){
        x = t.x;
    }

    ~Test(){};

    int GetX(){ return x;};

    double GetY(){ return y;};
};

int main(){

    Test* t = Singleton<Test>::Instance(10);
    cout << t->GetX() << " " << t->GetY() << endl;

}