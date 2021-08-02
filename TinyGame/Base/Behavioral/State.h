#ifndef BASE_BEHAVIORAL_STATE_H
#define BASE_BEHAVIORAL_STATE_H


#include <string_view>


namespace base::behavioral {
class State {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    State() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~State() = default;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual std::string_view GetName(void) const = 0;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="delta_time"></param>
    virtual void Update(float delta_time) = 0;
    /// <summary>
    /// �J�n
    /// </summary>
    /// <param name=""></param>
    virtual void Enter(void) = 0;
    /// <summary>
    /// �I��
    /// </summary>
    /// <param name=""></param>
    virtual void Exit(void) = 0;
};
}
#endif // !BASE_BEHAVIORAL_STATE_H