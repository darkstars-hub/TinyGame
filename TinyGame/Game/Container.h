//! 
//! @file Container.h
//! @brief abstruct container
//! @author darkstar
//! @date 2021/08/02
//! @details none
//! 
#ifndef GAME_CONTAINER_H
#define GAME_CONTAINER_H


#include <vector>

#include "Base/Core/Utility.h"
#include "Base/Exception/NamelessInstanceExeption.h"
#include "Base/Exception/ArgumentException.h"


namespace game {
template <typename Element>
class Container {
    using ElementVector = std::vector<Element>;
private:
    //! �e��
    const int _default_capacity;
    //! �v�f
    ElementVector _elements;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Container() :
        _default_capacity(32),
        _elements() {
        _elements.reserve(_default_capacity);
    }
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="capacity">�L���p�V�e�B�[</param>
    Container(int capacity) :
        _default_capacity(capacity),
        _elements() {
        _elements.reserve(_default_capacity);
    }
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Container() {
    }
    /// <summary>
    /// �擾
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    auto operator()(void) const {
        return &this->_elements;
    }
    /// <summary>
    /// begin
    /// </summary>
    /// <returns></returns>
    auto begin(void) {
        return _elements.begin();
    }
    /// <summary>
    /// end
    /// </summary>
    /// <returns></returns>
    auto end(void) {
        return _elements.end();
    }
    /// <summary>
    /// �擾
    /// </summary>
    /// <param name="name"></param>
    /// <returns></returns>
    Element Get(const std::string& name) {
        try {
            if (name.empty()) {
                throw base::exception::ArgumentException("ArgumentException");
            } // if

            auto& elems = _elements;
            auto it = std::find_if(elems.begin(), elems.end(), [&name](const Element& elem) {
                return elem->name == name;
            });
            if (it == elems.end()) {
                return Element();
            } // if
            return *it;
        } // try
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        } // catch
        return Element();
    }
    /// <summary>
    /// �ǉ�
    /// </summary>
    /// <param name="value">�l</param>
    void Add(const Element& value) {
        this->_elements.push_back(value);
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns>��</returns>
    bool Empty(void) const {
        return this->_elements.empty();
    }
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(void) {
        for (auto& element : _elements) {
            element->Initialize();
        } // for
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Input(float delta_time) {
        for (auto& element : _elements) {
        } // for
    }
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Update(float delta_time) {
        for (auto& element : _elements) {
            element->Update(delta_time);
        } // for
    }
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Render(void) {
        for (auto& element : _elements) {
        } // for
    }
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void) {
        for (auto& element : _elements) {
        } // for
    }
    /// <summary>
    /// ���t���b�V��
    /// </summary>
    /// <param name=""></param>
    void Refresh(void) {
        base::core::utility::EraseRemove(_elements, [](const auto& obj) {
            return obj->state == decltype(obj->state)::End;
        });
    }
};
}
#endif // !GAME_CONTAINER_H