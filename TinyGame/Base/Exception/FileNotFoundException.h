/**
* @file FileNotFoundException.h
* @brief 指定されたパス名で示されるファイルが開けなかった場合、存在しない場合、
*        なんらかの理由でアクセスできない場合にスローされる例外
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
    //! メッセージ
    std::string _message;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="message"></param>
    explicit FileNotFoundException(const std::string& message) :
        _message(message) {
    }
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <returns></returns>
    virtual ~FileNotFoundException() noexcept {
    }
    /// <summary>
    /// メッセージ
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual const char* what(void) const noexcept {
        return this->_message.c_str();
    }
};
}
#endif // !BASE_EXCEPTION_FILE_NOT_FOUND_EXEPTION_H