//
// Created by vincent on 18-3-11.
//

#pragma once
#define DEBUG
#define DISABLE_COPY_AND_ASSIGN(CLASS_NAME)\
        (CLASS_NAME)(const (CLASS_NAME));\
        (CLASS_NAME)& operator=(const (CLASS_NAME)&)


#ifdef DEBUG
#define LOG(format, arg...) fprintf(stderr, "LOG: FILE: %s Line: %3d \n", __FILE__, __LINE__); \
                            fprintf(stderr, format, ##arg);\
                            fprintf(stderr, "\n")
#else
#define LOG(format, arg...)
#endif

#define VLIB_PROGRAM(__PROGRAM_NAME__)\
        int flag = [](){\
            vlib::Program::Instance.reset(new __PROGRAM_NAME__());\
            return 0;\
        }();




