/**
* @file Setter.h
* @brief �Q�b�^�[
* @author nameless
* @date unknown
* @details none
*/
#ifndef BASE_ACCESSOR_SETTER_H
#define BASE_ACCESSOR_SETTER_H


#include "../Structural/ServiceLocator.h"


namespace base::accessor {
template<typename T>
class Setter {
public:
    using Type = T;
private:
    //! �f�[�^
    T* _value;
public:
    Setter(T& value) :
        _value(&value) {
    }
    ~Setter() {
        _value = nullptr;
    }
    Setter& operator =(const T& value) {
        *this->_value = value;
        return *this;
    }
};
template<typename T>
class Setter<base::structural::ServiceLocator<T>> {
    using Type = base::structural::ServiceLocator<T>;
private:
    //! �f�[�^
    base::structural::ServiceLocator<T>* _value;
public:
    Setter(base::structural::ServiceLocator<T>& value) :
        _value(&value) {
    }
    ~Setter() {
        _value = nullptr;
    }
    Setter<base::structural::ServiceLocator<T>>& operator = (const std::shared_ptr<T>& value) {
        *this->_value = value;
        return *this;
    }
};
}
#endif // !BASE_ACCESSOR_SETTER_H