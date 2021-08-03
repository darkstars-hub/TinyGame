#ifndef U22_FRAMEWORK_INPUT_INPUT_H
#define U22_FRAMEWORK_INPUT_INPUT_H


#include <memory>
#include <unordered_map>
#include <algorithm>

#include "../Framework/Window/Window.h"
#include "Keycode.h"


namespace u22::input {
class Input {
private:
    //! �E�C���h�E
    std::weak_ptr<u22::Window> _window;
    //! �L�[
    std::unordered_map<u22::input::KeyCode, bool> _previous_key_status;
    //! �L�[
    std::unordered_map<u22::input::KeyCode, bool> _current_key_status;
    //! �}�E�X
    std::unordered_map<u22::input::MouseButton, bool> _previous_mouse_button_status;
    //! �}�E�X
    std::unordered_map<u22::input::MouseButton, bool> _current_mouse_button_status;

    //! ���W
    double _mouse_x;
    //! ���W
    double _mouse_y;


    /// <summary>
    /// ����
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    /// <param name="key"></param>
    /// <param name="map"></param>
    /// <returns>����</returns>
    template<typename Key, typename Value>
    bool Contain(Key key, const std::unordered_map<Key, Value>& map) const {
        auto it = map.find(key);
        if (it != map.end()) {
            return true;
        } // if
        return false;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    /// <param name="key"></param>
    /// <param name="previous"></param>
    /// <param name="current"></param>
    /// <returns></returns>
    template<typename Key, typename Value>
    bool IsPush(Key key, const std::unordered_map<Key, Value>& previous, const std::unordered_map<Key, Value>& current) const {
        _ASSERT_EXPR(this->Contain(key, previous), L"���݂��Ȃ��L�[�ɂ��Ĕ��肵�悤�Ƃ��Ă��܂�");
        _ASSERT_EXPR(this->Contain(key, current), L"���݂��Ȃ��L�[�ɂ��Ĕ��肵�悤�Ƃ��Ă��܂�");

        bool prev = previous.at(key);
        bool now = current.at(key);
        return prev == false && now == true;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    /// <param name="key"></param>
    /// <param name="previous"></param>
    /// <param name="current"></param>
    /// <returns></returns>
    template<typename Key, typename Value>
    bool IsHold(Key key, const std::unordered_map<Key, Value>& previous, const std::unordered_map<Key, Value>& current) const {
        _ASSERT_EXPR(this->Contain(key, previous), L"���݂��Ȃ��L�[�ɂ��Ĕ��肵�悤�Ƃ��Ă��܂�");
        _ASSERT_EXPR(this->Contain(key, current), L"���݂��Ȃ��L�[�ɂ��Ĕ��肵�悤�Ƃ��Ă��܂�");

        bool prev = previous.at(key);
        bool now = current.at(key);
        return prev == true && now == true;
    }
    /// <summary>
    /// ����
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    /// <param name="key"></param>
    /// <param name="previous"></param>
    /// <param name="current"></param>
    /// <returns></returns>
    template<typename Key, typename Value>
    bool IsPull(Key key, const std::unordered_map<Key, Value>& previous, const std::unordered_map<Key, Value>& current) const {
        _ASSERT_EXPR(this->Contain(key, previous), L"���݂��Ȃ��L�[�ɂ��Ĕ��肵�悤�Ƃ��Ă��܂�");
        _ASSERT_EXPR(this->Contain(key, current), L"���݂��Ȃ��L�[�ɂ��Ĕ��肵�悤�Ƃ��Ă��܂�");

        bool prev = previous.at(key);
        bool now = current.at(key);
        return prev == true && now == false;
    }
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Input();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Input();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr"></param>
    void SetWindow(const std::shared_ptr<u22::Window>& ptr);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    float GetMouseX(void) const noexcept;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    float GetMouseY(void) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool IsPush(u22::input::KeyCode keycode) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="button"></param>
    /// <returns></returns>
    bool IsPush(u22::input::MouseButton button) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool IsHold(u22::input::KeyCode keycode) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="button"></param>
    /// <returns></returns>
    bool IsHold(u22::input::MouseButton button) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool IsPull(u22::input::KeyCode keycode) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="button"></param>
    /// <returns></returns>
    bool IsPull(u22::input::MouseButton button) const noexcept;
    /// <summary>
    /// �ǉ�
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool AddKey(u22::input::KeyCode keycode);
    /// <summary>
    /// �ǉ�
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool AddMouse(u22::input::MouseButton button);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    void Refresh(void);
};
}
#endif // !U22_FRAMEWORK_INPUT_INPUT_H