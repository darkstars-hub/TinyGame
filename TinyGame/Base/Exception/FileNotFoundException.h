/**
* @file FileNotFoundException.h
* @brief �w�肳�ꂽ�p�X���Ŏ������t�@�C�����J���Ȃ������ꍇ�A���݂��Ȃ��ꍇ�A
*        �Ȃ�炩�̗��R�ŃA�N�Z�X�ł��Ȃ��ꍇ�ɃX���[������O
* @author darkstars
* @date 2021/08/02
* @details none
*/
#ifndef BASE_EXCEPTION_FILE_NOT_FOUND_EXEPTION_H
#define BASE_EXCEPTION_FILE_NOT_FOUND_EXEPTION_H


#include <exception>
#include <string>


namespace base::exception {
class FileNotFoundException : public std::exception {
private:
    //! ���b�Z�[�W
    std::string _message;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="message"></param>
    explicit FileNotFoundException(const std::string& message) :
        _message(message) {
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    /// <returns></returns>
    virtual ~FileNotFoundException() noexcept {
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
#endif // !BASE_EXCEPTION_FILE_NOT_FOUND_EXEPTION_H