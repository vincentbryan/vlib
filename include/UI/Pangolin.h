//
// Created by vincent on 18-5-7.
//

#pragma once

#include <pangolin/pangolin.h>
#include "../Utils/Program.h"

namespace vlib{

    class Pangolin : public Program{

    public:
        explicit Pangolin();

    protected:

        void OnStart() override;

        void OnRun() override;

        void OnFinish() override;

    private:
        void AddPoint(float x, float y, float z, int color = 0xFF0000);


        pangolin::OpenGlRenderState s_cam;

        pangolin::View* d_cam ;

    };
}



