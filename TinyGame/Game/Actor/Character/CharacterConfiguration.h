//!
//! @file CharacterConfiguration.h
//! @brief キャラクタークラスを構成するパラメータ
//! @author darkstar
//! @date 2021_08_02
//! 
#ifndef GAME_ACTOR_CHARACTER_CHARACTER_CONFIGURATION_H
#define GAME_ACTOR_CHARACTER_CHARACTER_CONFIGURATION_H


#include "Base/Parameter/NameParameter.h"
#include "../../Parameter/Character/CharacterState.h"


namespace game::actor::character {
struct CharacterConfiguration {
    //! 名前
    base::parameter::NameParameter name;
    //! 状態
    game::parameter::character::CharacterState state;
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="str"></param>
    CharacterConfiguration(const std::string& str) : 
        name(str),
        state(decltype(state)::Active){
    }
};
}
#endif // !GAME_ACTOR_CHARACTER_CHARACTER_CONFIGURATION_H