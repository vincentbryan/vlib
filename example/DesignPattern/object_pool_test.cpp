#include <iostream>
#include <vlib>

using namespace std;
using namespace vlib;


class Foo{

public:

    int f;

    Foo(int f_ = 0) : f(f_){};
    Foo(const Foo& foo_) : f(foo_.f){};
    Foo& operator = (const Foo& foo_){
        this->f = foo_.f;
        return *this;
    }

};


class Test{

private:

    int x;
    double y;
    string s;
    Foo foo;

public:

    Test(int x_ = 10, double y_ = 0, string s_ = "Hello", Foo foo_ = Foo(0)) : x(x_), y(y_), s(s_), foo(foo_){
    };

    void print(){
        cout << x << " " << y << " " << s << " " << foo.f << endl;
    }

};


int main(){


    ObjectPool<Test> objectPool(2);

    string str = "Testing";
    Foo foo(2);
    objectPool.Init(2, 10, 4.5, str, foo);
//    objectPool.Init(2, 10, 4.5, "haha"); //Error !!!

    {
        {
            auto t1 = objectPool.Get<int, double, string, Foo>(); t1->print();
            auto t2 = objectPool.Get<int, double, string, Foo>(); t2->print();
        }

        auto t1 = objectPool.Get<int, double, string, Foo>(); t1->print();
        auto t2 = objectPool.Get<int, double, string, Foo>(); t2->print();
    }

    auto t1 = objectPool.Get<int, double, string, Foo>(); t1->print();
    auto t2 = objectPool.Get<int, double, string, Foo>(); t2->print();


    return 0;
}