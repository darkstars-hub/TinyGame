#ifndef BASE_BEHAVIORAL_OBSERVER_H
#define BASE_BEHAVIORAL_OBSERVER_H


namespace base::behavioral {
template<class...NotifyArgs>
class Observer {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Observer();
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~Observer();
    /// <summary>
    /// 通知イベント
    /// </summary>
    /// <param name="..."></param>
    virtual void OnNotify(NotifyArgs...) = 0;
};
template<class ...NotifyArgs>
inline Observer<NotifyArgs...>::Observer() {
}
template<class ...NotifyArgs>
inline Observer<NotifyArgs...>::~Observer() {
}
}
#endif // !BASE_BEHAVIORAL_OBSERVER_H