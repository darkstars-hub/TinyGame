#ifndef BASE_BEHAVIORAL_STATE_H
#define BASE_BEHAVIORAL_STATE_H


#include <string_view>


namespace base::behavioral {
class State {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    State() = default;
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~State() = default;
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual std::string_view GetName(void) const = 0;
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="delta_time"></param>
    virtual void Update(float delta_time) = 0;
    /// <summary>
    /// 開始
    /// </summary>
    /// <param name=""></param>
    virtual void Enter(void) = 0;
    /// <summary>
    /// 終了
    /// </summary>
    /// <param name=""></param>
    virtual void Exit(void) = 0;
};
}
#endif // !BASE_BEHAVIORAL_STATE_H