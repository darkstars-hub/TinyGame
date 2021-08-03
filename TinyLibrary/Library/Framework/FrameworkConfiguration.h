//! 
//! @file FrameworkConfiguration.h
//! @brief Frameworkの構成情報を定義
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_FRAMEWORK_FRAMEWORK_CONFIGURATION_H
#define LIBRARY_FRAMEWORK_FRAMEWORK_CONFIGURATION_H


#include <memory>

/*
#include "../Clock/Clock.h"
#include "../Window/Window.h"
#include "../Input/Input.h"
#include "../Graphics/Graphics.h"
#include "../Audio/Audio.h"
*/


namespace library::framework {
struct FrameworkInfo {
public:
    //! クロック
    //std::shared_ptr<library::clock::Clock> clock;
    //! ウインドウ
    //std::shared_ptr<library::Window> window;
    //! インプット
    //std::shared_ptr<library::input::Input> input;
    //! グラフィックス
    //std::shared_ptr<library::graphics::Graphics> graphics;
    //! オーディオ
    //std::shared_ptr<library::audio::Audio> audio;
    /// <summary>
    /// コンストラクタ
    /// </summary>
    FrameworkInfo() = default;
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~FrameworkInfo() = default;
};
}
#endif // !LIBRARY_FRAMEWORK_FRAMEWORK_CONFIGURATION_H