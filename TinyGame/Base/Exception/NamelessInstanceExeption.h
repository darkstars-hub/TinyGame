/**
* @file NamelessInstanceExeption.h
* @brief インスタンスに名前がない場合にスローされる例外
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
    //! メッセージ
    std::string _message;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="message"></param>
    explicit NamelessInstanceExeption(const std::string& message) :
        _message(message) {
    }
    /// <summary>
    /// デストラクタ
    /// </summary>
    /// <returns></returns>
    virtual ~NamelessInstanceExeption() noexcept {
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
#endif // !BASE_EXCEPTION_NAMELESS_INSTANCE_EXEPTION_H