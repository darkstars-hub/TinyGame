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
    //! アンドゥ
    std::vector<std::shared_ptr<base::behavioral::Command>> _undo_stack;
    //! リドゥ
    std::vector<std::shared_ptr<base::behavioral::Command>> _redo_stack;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    CommandHistory();
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~CommandHistory();
    /// <summary>
    /// 戻る
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Undo(void);
    /// <summary>
    /// 戻す
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Redo(void);
    /// <summary>
    /// 登録
    /// </summary>
    /// <param name="ptr"></param>
    /// <returns></returns>
    bool Record(const std::shared_ptr<base::behavioral::Command>& ptr);
};
}
#endif // !BASE_BEHAVIORAL_COMMAND_HISTORY_H