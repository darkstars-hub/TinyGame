#ifndef BASE_BEHAVIORAL_COMMAND_HISTORY_H
#define BASE_BEHAVIORAL_COMMAND_HISTORY_H


#include <memory>
#include <array>
#include <vector>
#include <algorithm>

#include "Command.h"


namespace base::behavioral {
class CommandHistory {
private:
    //! �A���h�D
    std::vector<std::shared_ptr<base::behavioral::Command>> _undo_stack;
    //! ���h�D
    std::vector<std::shared_ptr<base::behavioral::Command>> _redo_stack;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CommandHistory();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CommandHistory();
    /// <summary>
    /// �߂�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Undo(void);
    /// <summary>
    /// �߂�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Redo(void);
    /// <summary>
    /// �o�^
    /// </summary>
    /// <param name="ptr"></param>
    /// <returns></returns>
    bool Record(const std::shared_ptr<base::behavioral::Command>& ptr);
};
}
#endif // !BASE_BEHAVIORAL_COMMAND_HISTORY_H