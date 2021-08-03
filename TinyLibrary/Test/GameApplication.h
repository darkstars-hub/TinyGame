//! 
//! @file GameApplication.h
//! @brief アプリケーション
//! @author darkstar
//! @date 2021/08/03
//! 
#ifndef LIBRARY_TEST_GAME_APPLICATION_H
#define LIBRARY_TEST_GAME_APPLICATION_H


#include "TinyLibrary.h"


namespace test {
class GameApplicaion : public library::application::Applicaion {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameApplicaion();
    /// <summary>
    /// コンストラクタ
    /// </summary>
    virtual ~GameApplicaion();
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Initialize(void) override;
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) override;
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Render(void) override;
    /// <summary>
    /// 解放
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) override;
};
}
#endif // !LIBRARY_TEST_GAME_APPLICATION_H