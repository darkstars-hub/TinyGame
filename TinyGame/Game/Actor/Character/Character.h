//! 
//! @file Character.h
//! @brief game character
//! @author darkstar
//! @date 2021/08/02
//! @details none
//! 
#ifndef GAME_ACTOR_CHARACTER_CHARACTER_H
#define GAME_ACTOR_CHARACTER_CHARACTER_H


#include "CharacterConfiguration.h"
#include "Base/Accessor/Accessor.h"
#include "Base/Accessor/Getter.h"


namespace game::actor::character {
class Character {
private:
    //! 構成情報
    game::actor::character::CharacterConfiguration _configuration;
public:
    //! アクセッサ
    base::accessor::Accessor<decltype(_configuration.name)> name = (_configuration.name);
    //! アクセッサ
    base::accessor::Accessor<decltype(_configuration.state)> state = (_configuration.state);
    /// <summary>
    /// 名前付きコンストラクタ
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    static std::shared_ptr<game::actor::character::Character> MakeShared(void);
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Character();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Character();
};
using CharacterPtr = std::shared_ptr<game::actor::character::Character>;
}
#endif // !GAME_ACTOR_CHARACTER_CHARACTER_H