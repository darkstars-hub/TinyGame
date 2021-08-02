#ifndef BASE_CREATIONAL_FACTORY_H
#define BASE_CREATIONAL_FACTORY_H


#include <memory>
#include <string>
#include <unordered_map>

#include "Creator.h"


namespace base::creational {
template <typename T>
class Factory {
private:
    std::unordered_map<std::string, std::unique_ptr<base::creational::ICreator<T>>> _creators;
public:
    template<typename Derived, typename Builder>
    void Register(const std::string& key, const std::shared_ptr<Builder>& builder) {
        _creators[key] = std::make_unique<base::creational::Creator<T, Derived, Builder>>(builder);
    }
    /// <summary>
    /// çÏê¨
    /// </summary>
    /// <param name="key"></param>
    /// <returns></returns>
    std::shared_ptr<T> Create(const std::string& key) const {
        return _creators.at(key)->Create();
    }
};
}
#endif // !BASE_CREATIONAL_FACTORY_H