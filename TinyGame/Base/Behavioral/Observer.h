#ifndef BASE_BEHAVIORAL_OBSERVER_H
#define BASE_BEHAVIORAL_OBSERVER_H


namespace base::behavioral {
template<class...NotifyArgs>
class Observer {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Observer();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Observer();
    /// <summary>
    /// �ʒm�C�x���g
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