/**
* @file NameParameter.h
* @brief ���O�I�u�W�F�N�g
* @author darkstar
* @date 2021/08/02
* @details none
*/
#ifndef BASE_PARAMETER_NAME_PARAMETER_H
#define BASE_PARAMETER_NAME_PARAMETER_H


#include <string>


namespace base::parameter {
struct NameParameter {
    //! �l
    std::string value;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="str"></param>
    NameParameter(const std::string& str) :
        value(str){
    }
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    operator const std::string_view& (void) const {
        return this->value;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="obj"></param>
    /// <returns></returns>
    bool operator == (const NameParameter& obj) const {
        return this->value == obj.value;
    }
};
}
#endif // !BASE_PARAMETER_NAME_PARAMETER_H