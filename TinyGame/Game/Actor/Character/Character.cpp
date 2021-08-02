//! 
//! @file Character.cpp
//! @brief game character
//! @author darkstar
//! @date 2021/08/02
//! @details none
//! 
#include "Character.h"


std::shared_ptr<game::actor::character::Character> game::actor::character::Character::MakeShared(void) {
    return std::make_shared<game::actor::character::Character>();
}

game::actor::character::Character::Character() :
    _configuration("nameless"){
}

game::actor::character::Character::~Character() {
}
