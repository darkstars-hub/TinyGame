/**
* @file NamelessInstanceExeption.h
* @brief �C���X�^���X�ɖ��O���Ȃ��ꍇ�ɃX���[������O
* @author darkstars
* @date 2021/08/02
* @details none
*/
#ifndef BASE_EXCEPTION_NAMELESS_INSTANCE_EXEPTION_H
#define BASE_EXCEPTION_NAMELESS_INSTANCE_EXEPTION_H


#include <exception>
#include <string>


namespace base::exception {
class NamelessInstanceExeption : public std::exception {
private:
    //! ���b�Z�[�W
    std::string _message;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="message"></param>
    explicit NamelessInstanceExeption(const std::string& message) :
        _message(message) {
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    /// <returns></returns>
    virtual ~NamelessInstanceExeption() noexcept {
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
#endif // !BASE_EXCEPTION_NAMELESS_INSTANCE_EXEPTION_H