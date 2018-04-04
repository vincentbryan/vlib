#define DEBUG
#include <iostream>
#include <vlib>

using namespace vlib;
using namespace std;

int main() {
    string str = "hahah";
    cout << typeid("hahah").name() << endl;
    cout << typeid(char*[6]).name() << endl;
}
