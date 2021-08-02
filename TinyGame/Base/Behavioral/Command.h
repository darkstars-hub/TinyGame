#ifndef BASE_BEHAVIORAL_COMMAND_H
#define BASE_BEHAVIORAL_COMMAND_H


#include <memory>


namespace base::behavioral {
class Command {
private:
public:
    /// <summary>
    /// ���s
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Execute(void) = 0;
    /// <summary>
    /// �߂�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Undo(void) = 0;
};
}
#endif // !BASE_BEHAVIORAL_COMMAND_H