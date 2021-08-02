/**
* @file ArgumentException.h
* @brief ���\�b�h�ɓn���ꂽ�����̂����ꂩ�������ȏꍇ�ɃX���[������O
* @author darkstar
* @date 2021/08/02
* @details none
*/
#ifndef BASE_EXCEPTION_ARGUMENT_EXEPTION_H
#define BASE_EXCEPTION_ARGUMENT_EXEPTION_H


#include <exception>
#include <string>


namespace base::exception {
class ArgumentException : public std::exception {
private:
    //! ���b�Z�[�W
    std::string _message;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="message"></param>
    explicit ArgumentException(const std::string& message) :
        _message(message) {
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    /// <returns></returns>
    virtual ~ArgumentException() noexcept {
    }
    /// <summary>
    /// ���b�Z�[�W
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual const char* what(void) const noexcept {
        return this->_message.c_str();
    }
};
}
#endif // !BASE_EXCEPTION_ARGUMENT_EXEPTION_H