//#include "Timer.h"
//#include <thread>
//using namespace std;
//
//#ifdef _WIN32
//#	include <ctime>
//#else
//#	include <sys/time.h>
//#	include <unistd.h>
//#endif
//
//using namespace vlib;
//
//long Timer::ms()
//{
//    float ms = 0.0;
//
//#ifdef _WIN32
//    ms = clock();
//#else
//    timeval t;
//    gettimeofday(&t, NULL);
//    ms = t.tv_sec * 1000 + t.tv_usec * 1.0 / 1000.0;
//#endif
//
//    return ms;
//}
//
//void Timer::Sleep(long ms)
//{
//    this_thread::sleep_for(chrono::milliseconds(ms));
//}
