//! 
//! @file FrameworkConfiguration.h
//! @brief Framework�̍\�������`
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
    //! �N���b�N
    //std::shared_ptr<library::clock::Clock> clock;
    //! �E�C���h�E
    //std::shared_ptr<library::Window> window;
    //! �C���v�b�g
    //std::shared_ptr<library::input::Input> input;
    //! �O���t�B�b�N�X
    //std::shared_ptr<library::graphics::Graphics> graphics;
    //! �I�[�f�B�I
    //std::shared_ptr<library::audio::Audio> audio;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    FrameworkInfo() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FrameworkInfo() = default;
};
}
#endif // !LIBRARY_FRAMEWORK_FRAMEWORK_CONFIGURATION_H