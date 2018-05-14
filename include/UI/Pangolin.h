//
// Created by vincent on 18-5-7.
//

#pragma once

#include <mutex>
#include <pangolin/pangolin.h>
#include "../Utils/Program.h"
#define GetR(_color_) (((_color_ & 0xff0000) >> 16) * 1.0f / 255)
#define GetG(_color_) (((_color_ & 0x00ff00) >> 8) * 1.0f / 255)
#define GetB(_color_) (((_color_ & 0x0000ff)) * 1.0f / 255)
namespace vlib{

    class Pangolin : public Looper{

    public:
        Pangolin(int rate = 25, const string & windowName = "Pangolin");

        class Point{
        public:
            float x;
            float y;
            float z;
            explicit Point(float x_ = 0, float y_ = 0, float z_ = 0);
        };

        class Line{
        public:
            Pangolin::Point mStartPoint;
            Pangolin::Point mEndPoint;
            size_t mColor;
            explicit Line(const Pangolin::Point & startPoint, const Pangolin::Point & endPoint, size_t color);
        };

        class Cube{
        public:

            Pangolin::Point mCenter;
            float mRadius;
            float t;
            function<void(Pangolin::Cube & cube)> mCallBack;

            explicit Cube(float x_ = 0, float y_ = 0, float z_ = 0, float radius = 1, function<void(Pangolin::Cube & cube)> callback = nullptr)
                : mCenter(Pangolin::Point(x_, y_, z_)), mRadius(radius), mCallBack(callback){
                t= 0;
            };

        };

        void AddPoint(const float x, const float y,  const float z);

        void AddPoint(const Pangolin::Point & point);

        void AddLine(const Pangolin::Line & line);

        void AddLine(const Pangolin::Point & startPoint, const Pangolin::Point & endPoint, const size_t color);

        void AddLine(float x1, float y1, float z1, float x2, float y2, float z2, size_t color);

        void AddCube(float x, float y, float z, float r, function<void(Pangolin::Cube & cube)> callback = nullptr);

        float GetAxis() const{
            return this->mAxis;
        };

        void  SetAxis(const float length){
            std::lock_guard<std::mutex> lock(mAxisMutex);
            this->mAxis = length;
        };
    protected:

        void OnStart() override;

        void OnRun() override;

        void OnFinish() override;

        void DrawPoints();

        void DrawLines();

        void DrawAxis();

        void DrawCubes();

        void SetColor(int color);

    private:

        pangolin::OpenGlRenderState s_cam;

        pangolin::View* d_cam ;

        const string & mWindowName;

        vector<Pangolin::Point*> mPoints;

        vector<Pangolin::Line*>  mLines;

        vector<Pangolin::Cube*>  mCubes;

        std::mutex mPointMutex, mLineMutex, mAxisMutex, mCubeMutex;

        float mAxis;

    };
}



