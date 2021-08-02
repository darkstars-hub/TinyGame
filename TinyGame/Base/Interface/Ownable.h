#ifndef BASE_INTERFACE_OWNABLE_H
#define BASE_INTERFACE_OWNABLE_H


#include <memory>


namespace base::interface {
template<typename Owner>
class Ownable {
private:
    //! ���L��
    std::weak_ptr<Owner> _owner;
protected:
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�|�C���^</returns>
    std::shared_ptr<Owner> GetOwner(void) const {
        if (auto ptr = _owner.lock()) {
            return ptr;
        } // if
        return nullptr;
    }
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Ownable() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Ownable() = default;
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr">�|�C���^</param>
    void SetOwner(const std::shared_ptr<Owner>& ptr) {
        this->_owner = ptr;
    }
};
}
#endif // !BASE_INTERFACE_OWNABLE_H