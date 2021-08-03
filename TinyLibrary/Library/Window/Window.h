//! 
//! @file Window.h
//! @brief �E�C���h�E
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_WINDOW_WINDOW_H
#define LIBRARY_WINDOW_WINDOW_H


#include "../Common/Common.h"

#include <string>

#include "WindowCreateInfomation.h"


namespace library::window {
class Window {
private:
    //! �E�C���h�E
    ::GLFWwindow* _handle;
    //! �f�B�X�v���C
    ::GLFWmonitor* _monitor;
    //! �^�C�g��
    std::string _title;
    //! �T�C�Y
    int _width;
    //! �T�C�Y
    int _height;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Window();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Window();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr"></param>
    void SetHandle(::GLFWwindow* ptr);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ::GLFWwindow* GetHandle(void);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    int GetWidth(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    int GetHeight(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool ShouldClose(void);
    /// <summary>
    /// �쐬
    /// </summary>
    /// <param name="create_info"></param>
    /// <returns></returns>
    bool Create(const library::window::WindowCreateInfomation& create_info);
    /// <summary>
    /// �폜
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Destroy(void);
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    void Close(void) const;
    /// <summary>
    /// �t���b�v
    /// </summary>
    void Present(void) const;
    /// <summary>
    /// �C�x���g�|�[�����O
    /// </summary>
    /// <param name=""></param>
    void PollEvents(void) const;
};
}
#endif // LIBRARY_WINDOW_WINDOW_H