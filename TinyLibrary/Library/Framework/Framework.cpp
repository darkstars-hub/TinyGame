//! 
//! @file Framework.cpp
//! @brief フレームワーク
//! @author darkstar
//! @date 2021/08/03
//! 
#include "Framework.h"

/*
#include <filesystem>
library::framework::FrameworkInfo library::framework::Framework::_infomation;


bool library::framework::Framework::SetCurrentPath(const char* name) {
    std::filesystem::path default_path = std::filesystem::current_path();
    if (auto work = default_path.parent_path(); true) {
        work.append(name);
        if (std::filesystem::exists(work)) {
            std::filesystem::current_path(work);
            return true;
        } // if
    } // if

    auto current_path = default_path;
    current_path.append(name);
    if (std::filesystem::exists(current_path) && std::filesystem::is_directory(current_path)) {
        std::filesystem::current_path(current_path);
        return true;
    } // if
    return false;
}

library::framework::FrameworkInfo* library::framework::Framework::GetInfomation(void) {
    return &_infomation;
}
*/

library::framework::Framework::Framework()
    :_applicaion(),
    _window(std::make_shared<library::window::Window>()),
    _clock(std::make_shared<library::clock::Clock>())
//    _input(std::make_shared<library::input::Input>()),
//    _graphics(std::make_shared<library::graphics::Graphics>()),
//    _audio(std::make_shared<library::audio::Audio>()),
//    _input->SetWindow(_window);
//    _infomation.clock = _clock;
//    _infomation.window = _window;
//    _infomation.input = _input;
//    _infomation.graphics = _graphics;
//    _infomation.audio = _audio;
{
}

library::framework::Framework::~Framework() {
}

//bool library::framework::Framework::Setup(const std::shared_ptr<library::framework::IApplicaion>& ptr, library::framework::ApplicationInfo* info) {
bool library::framework::Framework::Setup(const std::shared_ptr<library::application::Applicaion>& ptr, const library::window::WindowCreateInfomation& window_create_info) {
    //SetCurrentPath("Resource");

    // ウインドウ
    if (!_window->Create(window_create_info)) {
        return false;
    } // if
    /*
    // グラフィクス
    if (!_graphics->Initialize(_window)) {
        return false;
    } // if
    // オーディオ
    if (!_audio->Initialize()) {
        return false;
    } // if

    */
    _applicaion = ptr;
    _applicaion->Initialize();
    return true;
}

int library::framework::Framework::Run(void) {
    while (!_window->ShouldClose()) {
        _clock->Tick();
        if (!_clock->IsFull()) {
            _clock->Wait(); continue;
        } // if
        _clock->Update();

        //_input->Refresh();
        _applicaion->Update();
        _applicaion->Render();

        _window->Present();
        _window->PollEvents();
    } // while
    return 0;
}

bool library::framework::Framework::Cleanup(void) {
    _applicaion->Release();

    /*
    _window->Destroy();
    _graphics->Release();
    _audio->Release();
    */
    return true;
}