#ifndef BASE_STRUCTURAL_SERVICE_LOCATOR_H
#define BASE_STRUCTURAL_SERVICE_LOCATOR_H


#include <memory>


namespace base::structural {
template<class Service>
class ServiceLocator {
private:
    //! �T�[�r�X
    std::shared_ptr<Service> _service;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <typeparam name="Service"></typeparam>
    ServiceLocator();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~ServiceLocator();
    /// <summary>
    /// ���
    /// </summary>
    /// <param name="ptr">�|�C���^</param>
    /// <returns></returns>
    ServiceLocator& operator =(const std::shared_ptr<Service>& ptr);
    /// <summary>
    /// �A�N�Z�X
    /// </summary>
    /// <param name=""></param>
    /// <returns>�|�C���^</returns>
    std::shared_ptr<Service> operator->(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="obj"></param>
    constexpr explicit operator bool(void) const;    
};
template<class Service>
inline ServiceLocator<Service>::ServiceLocator() {
}
template<class Service>
inline ServiceLocator<Service>::~ServiceLocator() {
}
template<class Service>
inline ServiceLocator<Service>& ServiceLocator<Service>::operator=(const std::shared_ptr<Service>& ptr) {
    this->_service = ptr;
    return *this;
}
template<class Service>
inline std::shared_ptr<Service> ServiceLocator<Service>::operator->(void) const {
    return this->_service;
}
template<class Service>
inline constexpr ServiceLocator<Service>::operator bool(void) const {
    if (this->_service) {
        return true;
    } // if
    return false;
}
}
#endif // !BASE_STRUCTURAL_SERVICE_LOCATOR_H