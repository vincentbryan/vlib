//
// Created by vincent on 18-3-12.
//

#include <chrono>

using namespace std::chrono;

namespace vlib{

    class Timer{

    private:

        time_point<high_resolution_clock> m_begin;

    public:

        Timer() : m_begin(high_resolution_clock::now()){}

        void Reset(){
            m_begin = high_resolution_clock::now();
        }

        template <typename Duration = milliseconds>
        int64_t Elapsed() const {
            return duration_cast<Duration>(high_resolution_clock::now() - m_begin).count();
        }

        int64_t ElapsedNano() const {
            return Elapsed<nanoseconds>();
        }

        int64_t ElapsedMicro() const {
            return Elapsed<milliseconds>();
        }

        int64_t ElapsedSecond() const {
            return Elapsed<seconds>();
        }

        int64_t ElapsedMinute() const {
            return Elapsed<minutes>();
        }

        int64_t ElapsedHour() const {
            return Elapsed<hours>();
        }


    };
}