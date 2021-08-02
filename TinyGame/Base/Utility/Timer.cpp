#include "Timer.h"


base::utility::Timer::Timer() :
    _time(0.0f),
    _time_max(0.0f),
    _loop(true),
    _stop(false) {
}

base::utility::Timer::~Timer() {
}

float base::utility::Timer::operator() (void) const {
    return this->_time;
}

void base::utility::Timer::Initialize(float max, bool loop, bool stop) {
    _time = 0.0f;
    _time_max = max;
    _loop = loop;
    _stop = stop;
}

bool base::utility::Timer::Tick(float delta_time) {
    if (_stop) {
        if (_time_max <= _time) {
            return false;
        } // if
    } // if
    
    _time += delta_time;

    if (_time_max <= _time) {
        if (_loop) {
            _time = 0.0f;
        } // if
        return true;
    } // if
    return false;
}