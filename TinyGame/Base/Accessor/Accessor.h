/**
* @file Accessor.h
* @brief �Q�b�^�[
* @author nameless
* @date unknown
* @details none
*/
#ifndef BASE_ACCESSOR_ACCESSOR_H
#define BASE_ACCESSOR_ACCESSOR_H


#include <type_traits>
#include <memory>


namespace base::accessor {
template<typename T>
class Accessor {
private:
    //! �f�[�^
    T* _value;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="value"></param>
    Accessor(T& value) :
        _value(&value) {
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    /// <param name="value"></param>
    ~Accessor() {
        _value = nullptr;
    }
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="value"></param>
    /// <returns></returns>
    Accessor& operator =(const T& value) {
        *this->_value = value;
        return *this;
    }
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    operator const T& (void) const {
        return *this->_value;
    }
    /// <summary>
    /// �A�N�Z�X
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    T* operator->(void) const {
        return this->_value;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="value"></param>
    /// <returns></returns>
    bool operator == (const T& value) const {
        return *this->_value == value;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="obj"></param>
    /// <returns></returns>
    bool operator == (const Accessor<T>& obj) const {
        return *this->_value == *obj._value;
    }
    /// <summary>
    /// ���Z
    /// </summary>
    /// <param name="value"></param>
    /// <returns></returns>
    Accessor& operator += (T* value) {
        *this->_value += *value;
        return *this;
    }
    /// <summary>
    /// ���Z
    /// </summary>
    /// <param name="value"></param>
    /// <returns></returns>
    Accessor& operator += (const T& value) {
        *this->_value += value;
        return *this;
    }
};
template<typename T>
class Accessor<std::shared_ptr<T>> {
private:
    //! �f�[�^
    std::shared_ptr<T> _value;
public:
    Accessor(std::shared_ptr<T>& value) :
        _value(value) {
    }
    ~Accessor() {
        _value = nullptr;
    }
    Accessor& operator =(const T& value) {
        *this->_value = value;
        return *this;
    }
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    operator const std::shared_ptr<T>& (void) const {
        return this->_value;
    }
    /// <summary>
    /// �A�N�Z�X
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    std::shared_ptr<T> operator->(void) const {
        return this->_value;
    }
};
}
#endif // !BASE_ACCESSOR_ACCESSOR_H