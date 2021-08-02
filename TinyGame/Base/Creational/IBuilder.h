#ifndef BASE_CREATIONAL_IBUILDER_H
#define BASE_CREATIONAL_IBUILDER_H


#include <string_view>


namespace base::creational {
class IBuilder {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    IBuilder() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~IBuilder() = default;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�^�C�v</returns>
    virtual std::string_view GetType(void) = 0;
    /// <summary>
    /// �\�z
    /// </summary>
    /// <param name=""></param>
    //virtual void Construct(std::any shared_this) = 0;
    /*
    template<typename Target>
    void Construct(const std::shared_ptr<Target>& ptr) {
    }
    */
};
}
#endif // !BASE_CREATIONAL_IBUILDER_H