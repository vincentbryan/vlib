//
// Created by vincent on 18-5-7.
//

#include "UI/Pangolin.h"
#include "macro.h"

using namespace vlib;

Pangolin::Pangolin(int rate, const string & windowName) : Looper(rate), mWindowName(windowName) {
    mAxis = 10.0f;
}

Pangolin::Point::Point(float x_, float y_, float z_)
    : x(x_), y(y_), z(z_){

}

Pangolin::Line::Line(const Pangolin::Point & startPoint, const Pangolin::Point & endPoint, size_t color)
    : mStartPoint(startPoint), mEndPoint(endPoint), mColor(color){};


void Pangolin::OnStart() {

    pangolin::CreateWindowAndBind(mWindowName,640,480);
    glEnable(GL_DEPTH_TEST);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    s_cam = pangolin::OpenGlRenderState(
        pangolin::ProjectionMatrix(640,480,420,420,320,240,0.2,100),
        pangolin::ModelViewLookAt(2, 2, 2, 0,0,0, pangolin::AxisZ)
    );

    d_cam =  &pangolin::CreateDisplay()
        .SetBounds(1.0, 0.0, 1.0, 0.0, -640.0f/480.0f)
        .SetHandler(new pangolin::Handler3D(s_cam));

}

void Pangolin::OnRun() {
    if (pangolin::ShouldQuit()){
        this->Finish();
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    d_cam->Activate(s_cam);

    DrawAxis();

    DrawLines();

    DrawCubes();

    pangolin::FinishFrame();

}

void Pangolin::OnFinish() {}

void Pangolin::AddPoint(const float x, const float y, const float z) {
    std::lock_guard<std::mutex> lock(mPointMutex);
    mPoints.emplace_back(new Pangolin::Point(x, y, z));
}

void Pangolin::AddPoint(const Pangolin::Point &point) {
    std::lock_guard<std::mutex> lock(mPointMutex);
    mPoints.emplace_back(new Pangolin::Point(point));
}

void Pangolin::DrawPoints(){

    std::lock_guard<std::mutex> lock(mPointMutex);

    for(auto & point: mPoints){
        glBegin(GL_POINTS);
        glVertex3f(point->x, point->y, point->z);
        glEnd();
    }

}

void Pangolin::DrawLines() {

    mLineMutex.lock();

    for (auto & line : mLines){
        size_t color = line->mColor;
        GLfloat cols1[]  = { GetR(color), GetG(color), GetB(color), GetR(color), GetG(color), GetB(color)};
        GLfloat verts1[] = { line->mStartPoint.x, line->mStartPoint.y, line->mStartPoint.z,
                             line->mEndPoint.x,   line->mEndPoint.y,   line->mEndPoint.z};
        pangolin::glDrawColoredVertices<float,float>(2, verts1, cols1, GL_LINES, 3, 3);
    }

    mLineMutex.unlock();

}

void Pangolin::DrawAxis() {
    if (mAxis > 0){
        std::lock_guard<std::mutex> lock(mAxisMutex);
        pangolin::glDrawAxis(mAxis);
    }
}

void Pangolin::DrawCubes() {

    std::lock_guard<std::mutex> lock(mCubeMutex);

    for (auto & cube : mCubes){

        if(cube->mCallBack) cube->mCallBack(*cube);

        GLfloat l = -1 * cube->mRadius;
        GLfloat h = cube->mRadius;

        GLfloat verts[] = {
            l,l,h,  h,l,h,  l,h,h,  h,h,h,  // FRONT
            l,l,l,  l,h,l,  h,l,l,  h,h,l,  // BACK
            l,l,h,  l,h,h,  l,l,l,  l,h,l,  // LEFT
            h,l,l,  h,h,l,  h,l,h,  h,h,h,  // RIGHT
            l,h,h,  h,h,h,  l,h,l,  h,h,l,  // TOP
            l,l,h,  l,l,l,  h,l,h,  h,l,l   // BOTTOM
        };

        for (int i = 0; i < 24; ++i) {
            verts[3*i] += cube->mCenter.x;
            verts[3*i + 1] += cube->mCenter.y;
            verts[3*i + 2] += cube->mCenter.z;
        }

        glVertexPointer(3, GL_FLOAT, 0, verts);
        glEnableClientState(GL_VERTEX_ARRAY);

        glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);

        glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 12, 4);

        glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
        glDrawArrays(GL_TRIANGLE_STRIP, 16, 4);
        glDrawArrays(GL_TRIANGLE_STRIP, 20, 4);

        glDisableClientState(GL_VERTEX_ARRAY);
    }

}

void Pangolin::SetColor(int color) {
    glColor3f(GetR(color), GetG(color), GetB(color));
}

void Pangolin::AddLine(const Pangolin::Line & line) {

    std::lock_guard<std::mutex> lock(mLineMutex);

    mLines.emplace_back(new Pangolin::Line(line));

}

void Pangolin::AddLine(const Pangolin::Point &startPoint, const Pangolin::Point &endPoint, const size_t color) {

    std::lock_guard<std::mutex> lock(mLineMutex);

    mLines.emplace_back(new Pangolin::Line(startPoint, endPoint, color));
}

void Pangolin::AddLine(float x1, float y1, float z1, float x2, float y2, float z2, size_t color) {
    Pangolin::Point startPoint(x1, y1, z1);
    Pangolin::Point endPoint(x2, y2, z2);
    AddLine(startPoint, endPoint, color);
}

void Pangolin::AddCube(float x, float y, float z, float r, function<void(Pangolin::Cube & cube)> callback) {
    std::lock_guard<std::mutex> lock(mCubeMutex);
    mCubes.emplace_back(new Pangolin::Cube(x, y, z, r, callback));
}




