#ifndef BASE_CREATIONAL_CREATOR_H
#define BASE_CREATIONAL_CREATOR_H


#include <memory>

#include "IBuilder.h"


namespace base::creational {
template <typename T>
class ICreator {
public:
    /// <summary>
    /// 作成
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual std::shared_ptr<T> Create(void) const = 0;
};
template <typename Base, typename Derived, typename Builder>
class Creator : public base::creational::ICreator<Base> {
private:
    //! 生成引数を保持
    std::shared_ptr<Builder> _builder;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="builder"></param>
    Creator(const std::shared_ptr<Builder> builder) :
        _builder(builder) {
    }
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~Creator() = default;
    /// <summary>
    /// 作成
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual std::shared_ptr<Base> Create(void) const override {
        auto ptr = std::make_shared<Derived>();
        _builder->Construct(ptr);
        return ptr;
    }
};
}
#endif // !BASE_CREATIONAL_CREATOR_H