//
// Created by vincent on 18-5-7.
//

#include "UI/Pangolin.h"

using namespace vlib;

Pangolin::Pangolin(){

    s_cam = pangolin::OpenGlRenderState(
                          pangolin::ProjectionMatrix(640,480,420,420,320,240,0.2,100),
                          pangolin::ModelViewLookAt(2, 2, 2, 0,0,0, pangolin::AxisZ)
                      );
    pangolin::Handler3D handler(s_cam);
    d_cam =   &pangolin::CreateDisplay()
              .SetBounds(1.0, 0.0, 1.0, 0.0, -640.0f/480.0f)
              .SetHandler(&handler);
}

void Pangolin::OnStart() {

}

void Pangolin::OnRun() {
    if (pangolin::ShouldQuit())
        return;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    d_cam->Activate(s_cam);

    // Render OpenGL Cube
    pangolin::glDrawColouredCube();
    pangolin::glDrawAxis(100);

    // Swap frames and Process Events
    pangolin::FinishFrame();

}

void Pangolin::OnFinish() {

}
