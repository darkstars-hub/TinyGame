#include "StateMachine.h"


std::string_view base::behavioral::StateMachine::GetCurrentStateName(void) const {
    return _current_state->GetName();
}

bool base::behavioral::StateMachine::EnableState(void) const {
    return _current_state.get();
}

void base::behavioral::StateMachine::RegisterState(const std::shared_ptr<base::behavioral::State>& ptr) {
    _ASSERT_EXPR(std::strlen(ptr->GetName().data()) != 0, L"State‚É–¼‘O‚ª‚ ‚è‚Ü‚¹‚ñ");
    _status.emplace(ptr->GetName(), ptr);
}

void base::behavioral::StateMachine::ChangeState(const std::string& name) {
//    _stack.clear();
    // Œ»Ý‚Ìó‘Ô‚ðI—¹‚·‚é
    if (_current_state) {
        _current_state->Exit();
    } // if
    // ó‘Ô‚Ì•ÏX
    auto it = _status.find(name);
    if (it != _status.end()) {
        _current_state = it->second;
        _current_state->Enter();
    } // if
    else {
        _current_state = nullptr;
    } // else
}

/*
void base::behavioral ::StateMachine::PushState(const std::string& name) {
    _stack.push_back(_status.at(name));
    _current_state = _stack.back();
}

void base::behavioral ::StateMachine::PopState(void) {
    _stack.pop_back();
}
*/

void base::behavioral::StateMachine::Update(float delta_time) {
    if (!_current_state) {
        return;
    } // if
    _current_state->Update(delta_time);
}

void base::behavioral::StateMachine::Release(void) {
    _current_state.reset();
    for (auto& state : _status) {
        state.second.reset();
    } // for
    _status.clear();
}