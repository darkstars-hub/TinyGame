/**
* @file ArgumentException.h
* @brief メソッドに渡された引数のいずれかが無効な場合にスローされる例外
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
    //! メッセージ
    std::string _message;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="message"></param>
    explicit ArgumentException(const std::string& message) :
        _message(message) {
    }
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <returns></returns>
    virtual ~ArgumentException() noexcept {
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
#endif // !BASE_EXCEPTION_ARGUMENT_EXEPTION_H