#include "CommandHistory.h"


base::behavioral::CommandHistory::CommandHistory() :
    _undo_stack(),
    _redo_stack() {
}

base::behavioral::CommandHistory::~CommandHistory() {
}

bool base::behavioral::CommandHistory::Undo(void) {
    if (_undo_stack.size() <= 0) {
        return false;
    } // if
    auto command = _undo_stack.back();
    command->Undo();

    _undo_stack.pop_back();
    _redo_stack.push_back(command);
    return true;
}

bool base::behavioral::CommandHistory::Redo(void) {
    if (_redo_stack.size() <= 0) {
        return false;
    } // if
    auto command = _redo_stack.back();
    command->Execute();

    _redo_stack.pop_back();
    _undo_stack.push_back(command);
    return true;
}

bool base::behavioral::CommandHistory::Record(const std::shared_ptr<base::behavioral::Command>& ptr) {
    ptr->Execute();
    _undo_stack.push_back(ptr);
    _redo_stack.clear();
    return true;
}