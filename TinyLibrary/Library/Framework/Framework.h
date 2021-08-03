//! 
//! @file Framework.h
//! @brief フレームワーク
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
    //! 構成情報
    //static library::FrameworkInfo _infomation;
    //! アプリケーション
    std::shared_ptr<library::application::Applicaion> _applicaion;
    //! ウインドウ
    std::shared_ptr<library::window::Window> _window;
    //! クロック
    std::shared_ptr<library::clock::Clock> _clock;
    /*
    //! インプット
    std::shared_ptr<library::input::Input> _input;
    //! グラフィックス
    std::shared_ptr<library::graphics::Graphics> _graphics;
    //! オーディオ
    std::shared_ptr<library::audio::Audio> _audio;
    */
public:
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    //static library::FrameworkInfo* GetInfomation(void);
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Framework();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Framework();
    /// <summary>
    /// セットアップ
    /// </summary>
    /// <param name="ptr"></param>
    /// <param name="window_create_info"></param>
    /// <returns></returns>
    bool Setup(const std::shared_ptr<library::application::Applicaion>& ptr, const library::window::WindowCreateInfomation& window_create_info);
    /// <summary>
    /// 実行
    /// </summary>
    /// <param name=""></param>
    /// <returns>結果</returns>
    int Run(void);
    /// <summary>
    /// クリーンナップ
    /// </summary>
    /// <param name=""></param>
    /// <returns>成功</returns>
    bool Cleanup(void);
};
}
#endif // !LIBRARY_FRAMEWORK_FRAMEWORK_H