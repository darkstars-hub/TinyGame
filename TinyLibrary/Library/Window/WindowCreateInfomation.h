//! 
//! @file Window.h
//! @brief ウインドウ
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_WINDOW_WINDOW_CREATE_INFOMATION_H
#define LIBRARY_WINDOW_WINDOW_CREATE_INFOMATION_H


#include <string>


namespace library::window {
struct WindowCreateInfomation {
    //! タイトル
    std::string title;
    //! サイズ
    int width;
    //! サイズ
    int height;
    //! 位置
    int position_x;
    //! 位置
    int position_y;
    //! フルスクリーン
    bool full_screen_mode;
};
}
#endif // LIBRARY_WINDOW_WINDOW_CREATE_INFOMATION_H