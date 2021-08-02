//! 
//! @file GameApplication.h
//! @brief game application
//! @author darkstar
//! @date 2021/08/02
//! @details none
//! 
#ifndef GAME_GAME_APPLICATION_H
#define GAME_GAME_APPLICATION_H


#include "Actor/Character/Character.h"
#include "Container.h"


namespace game {
class GameApplication {
private:
    //! 仮
    game::actor::character::Character _chara;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    GameApplication();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~GameApplication();
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(void);
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Update(float delta_time);
    /// <summary>
    /// 解放
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !GAME_GAME_APPLICATION_H