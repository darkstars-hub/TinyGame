#ifndef BASE_BEHAVIORAL_OBSERVABLE_H
#define BASE_BEHAVIORAL_OBSERVABLE_H


#include <memory>
#include <vector>

#include "../Core/Utility.h"
#include "Observer.h"


namespace base::behavioral {
template<class...NotifyArgs>
class Observable {
    using Observer = base::behavioral::Observer<NotifyArgs...>;
private:
    //! �I�u�U�[�o
    std::vector<std::weak_ptr<Observer>> _observers;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Observable() :
        _observers() {
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Observable() {
    }
    /// <summary>
    /// �ǉ�
    /// </summary>
    /// <param name="observer"></param>
    void AddObserver(const std::shared_ptr<Observer>& observer) {
        _observers.push_back(observer);
    }
    /// <summary>
    /// �폜
    /// </summary>
    /// <param name="observer"></param>
    void RemoveObserver(const std::shared_ptr<Observer>& observer) {
        base::core::utility::EraseRemove(_observers, [observer](const std::weak_ptr<Observer>& weak) {
            if (auto ptr = weak.lock()) {
                return ptr == observer;
            } // if
            return false;
        });
    }
    /// <summary>
    /// �ʒm
    /// </summary>
    /// <param name="...args"></param>
    void Notify(NotifyArgs... args) {
        auto& o = _observers;
        std::for_each(o.begin(), o.end(), [&](std::weak_ptr<Observer> weak) {
            if (auto ptr = weak.lock()) {
                ptr->OnNotify(args...);
            } // if
        });
    }
    /// <summary>
    /// �N���A
    /// </summary>
    /// <param name=""></param>
    void Clear(void) {
        _observers.clear();
    }
    /// <summary>
    /// ���t���b�V��
    /// </summary>
    /// <param name=""></param>
    void Refresh(void) {
        utility::EraseRemove(_observers, [](std::weak_ptr<Observer> weak) {
            return weak.expired();
        });
    }
};
}
#endif // !BASE_BEHAVIORAL_OBSERVABLE_H