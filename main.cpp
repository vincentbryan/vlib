#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(int argc, char ** argv) {

    Vector2d a(1, 2);
    Vector2d b(3, 4);

    cout << a + b << endl;

    return 0;
}