//! 
//! @file Framework.h
//! @brief �t���[�����[�N
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_FRAMEWORK_FRAMEWORK_H
#define LIBRARY_FRAMEWORK_FRAMEWORK_H


#include <memory>

#include "../Application/Application.h"
#include "../Window/Window.h"
#include "../Clock/Clock.h"


namespace library::framework {
class Framework {
private:
    //! �\�����
    //static library::FrameworkInfo _infomation;
    //! �A�v���P�[�V����
    std::shared_ptr<library::application::Applicaion> _applicaion;
    //! �E�C���h�E
    std::shared_ptr<library::window::Window> _window;
    //! �N���b�N
    std::shared_ptr<library::clock::Clock> _clock;
    /*
    //! �C���v�b�g
    std::shared_ptr<library::input::Input> _input;
    //! �O���t�B�b�N�X
    std::shared_ptr<library::graphics::Graphics> _graphics;
    //! �I�[�f�B�I
    std::shared_ptr<library::audio::Audio> _audio;
    */
public:
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    //static library::FrameworkInfo* GetInfomation(void);
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Framework();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Framework();
    /// <summary>
    /// �Z�b�g�A�b�v
    /// </summary>
    /// <param name="ptr"></param>
    /// <param name="window_create_info"></param>
    /// <returns></returns>
    bool Setup(const std::shared_ptr<library::application::Applicaion>& ptr, const library::window::WindowCreateInfomation& window_create_info);
    /// <summary>
    /// ���s
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    int Run(void);
    /// <summary>
    /// �N���[���i�b�v
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    bool Cleanup(void);
};
}
#endif // !LIBRARY_FRAMEWORK_FRAMEWORK_H