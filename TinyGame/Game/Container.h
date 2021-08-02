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
    //! 容量
    const int _default_capacity;
    //! 要素
    ElementVector _elements;
public:
    /// <summary>
    /// コンストラクタ
    /// </summary>
    Container() :
        _default_capacity(32),
        _elements() {
        _elements.reserve(_default_capacity);
    }
    /// <summary>
    /// コンストラクタ
    /// </summary>
    /// <param name="capacity">キャパシティー</param>
    Container(int capacity) :
        _default_capacity(capacity),
        _elements() {
        _elements.reserve(_default_capacity);
    }
    /// <summary>
    /// デストラクタ
    /// </summary>
    ~Container() {
    }
    /// <summary>
    /// 取得
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
    /// 取得
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
    /// 追加
    /// </summary>
    /// <param name="value">値</param>
    void Add(const Element& value) {
        this->_elements.push_back(value);
    }
    /// <summary>
    /// 判定
    /// </summary>
    /// <param name=""></param>
    /// <returns>空</returns>
    bool Empty(void) const {
        return this->_elements.empty();
    }
    /// <summary>
    /// 初期化
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(void) {
        for (auto& element : _elements) {
            element->Initialize();
        } // for
    }
    /// <summary>
    /// 入力
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Input(float delta_time) {
        for (auto& element : _elements) {
        } // for
    }
    /// <summary>
    /// 更新
    /// </summary>
    /// <param name="delta_time"></param>
    /// <returns></returns>
    bool Update(float delta_time) {
        for (auto& element : _elements) {
            element->Update(delta_time);
        } // for
    }
    /// <summary>
    /// 描画
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Render(void) {
        for (auto& element : _elements) {
        } // for
    }
    /// <summary>
    /// 解放
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void) {
        for (auto& element : _elements) {
        } // for
    }
    /// <summary>
    /// リフレッシュ
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