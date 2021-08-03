//! 
//! @file Window.h
//! @brief �E�C���h�E
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_WINDOW_WINDOW_CREATE_INFOMATION_H
#define LIBRARY_WINDOW_WINDOW_CREATE_INFOMATION_H


#include <string>


namespace library::window {
struct WindowCreateInfomation {
    //! �^�C�g��
    std::string title;
    //! �T�C�Y
    int width;
    //! �T�C�Y
    int height;
    //! �ʒu
    int position_x;
    //! �ʒu
    int position_y;
    //! �t���X�N���[��
    bool full_screen_mode;
};
}
#endif // LIBRARY_WINDOW_WINDOW_CREATE_INFOMATION_H