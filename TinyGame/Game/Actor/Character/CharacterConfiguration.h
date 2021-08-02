//!
//! @file CharacterConfiguration.h
//! @brief �L�����N�^�[�N���X���\������p�����[�^
//! @author darkstar
//! @date 2021_08_02
//! 
#ifndef GAME_ACTOR_CHARACTER_CHARACTER_CONFIGURATION_H
#define GAME_ACTOR_CHARACTER_CHARACTER_CONFIGURATION_H


#include "Base/Parameter/NameParameter.h"
#include "../../Parameter/Character/CharacterState.h"


namespace game::actor::character {
struct CharacterConfiguration {
    //! ���O
    base::parameter::NameParameter name;
    //! ���
    game::parameter::character::CharacterState state;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="str"></param>
    CharacterConfiguration(const std::string& str) : 
        name(str),
        state(decltype(state)::Active){
    }
};
}
#endif // !GAME_ACTOR_CHARACTER_CHARACTER_CONFIGURATION_H