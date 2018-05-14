//
// Created by vincent on 18-5-9.
//

#include <vlib>

using namespace vlib;


int main(int argc, int * argv[]){

    Pangolin pangolin(25);

    pangolin.AddLine(1, 0, 1, 0, 1, 1, 0x8B4E96);

    pangolin.AddCube(1, 1, 1, 1, [](Pangolin::Cube & cube){
        cube.t += 0.5;
        if(cube.t > 100) cube.t = 0;
        cube.mRadius = cube.t / 10;
    });


    pangolin.Start();

    pangolin.AddLine(0, 0, 0, 1, 1, 1, 0x8B4E96);

    if(pangolin.Joinable()) pangolin.Join();

}
