//! 
//! @file Clock.cpp
//! @brief ���C�u�������ł̎��v
//! @author darkstar
//! @date 2021/08/03
//! 
#include "Clock.h"


void library::clock::Clock::CalculateFPS(void) {
    auto front = _delta_times.front();
    _delta_times.pop_front();
    _delta_times_sum -= front;

    _delta_times.push_back(_delta_time);
    _delta_times_sum += _delta_time;

    auto average = _delta_times_sum / _sample_count;
    _now_fps = 1.0f / average;
}

library::clock::Clock::Clock() :
    _delta_time (),
    _previous_time(),
    _ideal_fps(60.0f),
    _now_fps(0.0f),
    _sample_count(60),
    _delta_times_sum(0.0f),
    _delta_times() {
    ::glfwSetTime(0.0);
    _delta_times.resize(_sample_count, 1.0f / _ideal_fps);
    for (const auto& delta : _delta_times) {
        _delta_times_sum += delta;
    } // for
}

library::clock::Clock::~Clock() {
}

float library::clock::Clock::GetFrameSecond(void) const {
    return this->_delta_time;
}

float library::clock::Clock::GetIdealFPS(void) const noexcept {
    return _ideal_fps;
}

float library::clock::Clock::GetFPS(void) const noexcept {
    return _now_fps;
}

bool library::clock::Clock::IsFull(void) {
    return  1.0f / _ideal_fps <= _delta_time;
}

void library::clock::Clock::Wait(void) {
    _delta_time += (1.0f / _ideal_fps) - _delta_time;
}

void library::clock::Clock::Tick(void) {
    auto current_time = static_cast<float>(::glfwGetTime());
    _delta_time = current_time - _previous_time;
    this->CalculateFPS();
}

void library::clock::Clock::Update(void) {
    _previous_time = static_cast<float>(::glfwGetTime());
}