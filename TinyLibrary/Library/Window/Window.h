//! 
//! @file Window.h
//! @brief ウインドウ
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
    //! ウインドウ
    ::GLFWwindow* _handle;
    //! ディスプレイ
    ::GLFWmonitor* _monitor;
    //! タイトル
    std::string _title;
    //! サイズ
    int _width;
    //! サイズ
    int _height;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Window();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Window();
    /// <summary>
    /// セッター
    /// </summary>
    /// <param name="ptr"></param>
    void SetHandle(::GLFWwindow* ptr);
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ::GLFWwindow* GetHandle(void);
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    int GetWidth(void) const;
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    int GetHeight(void) const;
    /// <summary>
    /// 判定
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool ShouldClose(void);
    /// <summary>
    /// 作成
    /// </summary>
    /// <param name="create_info"></param>
    /// <returns></returns>
    bool Create(const library::window::WindowCreateInfomation& create_info);
    /// <summary>
    /// 削除
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Destroy(void);
    /// <summary>
    /// 閉じる
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    void Close(void) const;
    /// <summary>
    /// フリップ
    /// </summary>
    void Present(void) const;
    /// <summary>
    /// イベントポーリング
    /// </summary>
    /// <param name=""></param>
    void PollEvents(void) const;
};
}
#endif // LIBRARY_WINDOW_WINDOW_H