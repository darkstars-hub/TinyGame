#ifndef BASE_CREATIONAL_IBUILDER_H
#define BASE_CREATIONAL_IBUILDER_H


#include <string_view>


namespace base::creational {
class IBuilder {
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    IBuilder() = default;
    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~IBuilder() = default;
    /// <summary>
    /// ゲッター
    /// </summary>
    /// <param name=""></param>
    /// <returns>タイプ</returns>
    virtual std::string_view GetType(void) = 0;
    /// <summary>
    /// 構築
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