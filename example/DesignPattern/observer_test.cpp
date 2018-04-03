#include <iostream>
#include <vlib>

using namespace std;
using namespace vlib;

class Test{
private:
    int* ptr= nullptr;

public:
    Test(int x = 1024) : ptr(new int(x)){};

    Test(Test&& t) : ptr(t.ptr){
        t.ptr = nullptr;
        cout << "move construct function is called" << endl;
    }

    Test(const Test& t) : ptr(new int(*t.ptr)){
        cout << "copy construct function is called" << endl;
    }

    Test operator = (const Test& t){
        this->ptr = new int(*t.ptr);
        cout << "assign function is called" << endl;
    }

    ~Test(){
        delete this->ptr;
        cout << "destroy function is called" << endl;
    }

    void print(int a, int b){
        cout << a << " " << b << " " << *ptr << endl;
    }

};

int main(){

    Subject<function<void(int, int)>> subject;

    int m = 10;
    subject.AddObserver([&](int a, int b){
       cout << a << " " << b << " " <<  m << endl;
    });

    Test t(-1);
    subject.AddObserver(bind(&Test::print, t, placeholders::_1, placeholders::_2));

    subject.Notify(1, 2);

    return 0;
}