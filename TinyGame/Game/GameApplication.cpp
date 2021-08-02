//! 
//! @file GameApplication.cpp
//! @brief game application
//! @author darkstar
//! @date 2021/08/02
//! @details none
//! 
#include "GameApplication.h"

#include "Actor/Character/Character.h"
#include "Container.h"


game::GameApplication::GameApplication() {
}

game::GameApplication::~GameApplication() {
}

bool game::GameApplication::Initialize(void) {
    game::Container<game::actor::character::CharacterPtr> chara_vec;
    auto chara = game::actor::character::Character::MakeShared();
    auto chara2 = game::actor::character::Character::MakeShared();
    chara_vec.Add(chara);
    chara_vec.Add(chara2);
    chara2->name = std::string("AA");
    auto c = chara_vec.Get("");
    std::string_view name = chara->name->value;
    //auto n = name.value;
    return true;
}

bool game::GameApplication::Update(float delta_time) {
    return true;
}

bool game::GameApplication::Release(void) {
    return true;
}
