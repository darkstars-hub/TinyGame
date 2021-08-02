#ifndef BASE_INTERFACE_OWNABLE_H
#define BASE_INTERFACE_OWNABLE_H


#include <memory>


namespace base::interface {
template<typename Owner>
class Ownable {
private:
    //! 所有者
    std::weak_ptr<Owner> _owner;
protected:
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns>ポインタ</returns>
    std::shared_ptr<Owner> GetOwner(void) const {
        if (auto ptr = _owner.lock()) {
            return ptr;
        } // if
        return nullptr;
    }
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Ownable() = default;
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~Ownable() = default;
    /// <summary>
    /// セッター
    /// </summary>
    /// <param name="ptr">ポインタ</param>
    void SetOwner(const std::shared_ptr<Owner>& ptr) {
        this->_owner = ptr;
    }
};
}
#endif // !BASE_INTERFACE_OWNABLE_H