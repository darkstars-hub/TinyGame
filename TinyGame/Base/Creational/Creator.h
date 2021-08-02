#ifndef BASE_CREATIONAL_CREATOR_H
#define BASE_CREATIONAL_CREATOR_H


#include <memory>

#include "IBuilder.h"


namespace base::creational {
template <typename T>
class ICreator {
public:
    /// <summary>
    /// �쐬
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual std::shared_ptr<T> Create(void) const = 0;
};
template <typename Base, typename Derived, typename Builder>
class Creator : public base::creational::ICreator<Base> {
private:
    //! ����������ێ�
    std::shared_ptr<Builder> _builder;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="builder"></param>
    Creator(const std::shared_ptr<Builder> builder) :
        _builder(builder) {
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~Creator() = default;
    /// <summary>
    /// �쐬
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