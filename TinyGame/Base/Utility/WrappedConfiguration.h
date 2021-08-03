#ifndef BASE_UTILITY_WRAPPED_CONFIGURATION_H
#define BASE_UTILITY_WRAPPED_CONFIGURATION_H


#include <variant>


namespace base::utility {
template<typename... Args>
class WrappedConfiguration {
private:
    //! �\�����
    std::variant<Args...> _configuration;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    WrappedConfiguration() {
    }
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <typeparam name="Config"></typeparam>
    /// <param name="obj"></param>
    template<typename Config>
    WrappedConfiguration(const Config& obj) :
        _configuration(obj) {
    }
    /// <summary>
    /// ���o���Ď󂯓n��
    /// </summary>
    /// <typeparam name="Config"></typeparam>
    /// <param name="in"></param>
    /// <returns></returns>
    template<typename Config>
    bool Fetch(Config& in) {
        if (std::holds_alternative<Config>(_configuration)) {
            in = std::get<Config>(_configuration);
            return true;
        } // if
        return false;
    }
};
}
#endif // !BASE_UTILITY_WRAPPED_CONFIGURATION_H