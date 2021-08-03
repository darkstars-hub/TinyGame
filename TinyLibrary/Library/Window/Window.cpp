#include "Window.h"


library::window::Window::Window() :
    _handle(),
    _monitor(),
    _title(),
    _width(),
    _height() {
}

library::window::Window::~Window() {
}

void library::window::Window::SetHandle(::GLFWwindow* ptr) {
    this->_handle = ptr;
}

::GLFWwindow* library::window::Window::GetHandle(void) {
    return this->_handle;
}

int library::window::Window::GetWidth(void) const {
    return this->_width;
}

int library::window::Window::GetHeight(void) const {
    return this->_height;
}

bool library::window::Window::ShouldClose(void) {
    return ::glfwWindowShouldClose(_handle);
}

bool library::window::Window::Create(const library::window::WindowCreateInfomation& create_info) {
    _title = create_info.title;
    _width = create_info.width;
    _height = create_info.height;
    _monitor = ::glfwGetPrimaryMonitor();
    auto mode = ::glfwGetVideoMode(_monitor);

    if (create_info.full_screen_mode) {
        _handle = ::glfwCreateWindow(_width, _height, _title.c_str(), _monitor, nullptr);
        ::glfwSetWindowMonitor(_handle, _monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
    } // if
    else {
        _handle = ::glfwCreateWindow(_width, _height , _title.c_str(), nullptr, nullptr);
    } // else

    if (!_handle) {
        ::glfwTerminate();
        return false;
    } // if
    ::glfwMakeContextCurrent(_handle);
    ::glfwSetWindowPos(_handle, create_info.position_x, create_info.position_y);
    ::glfwShowWindow(_handle);
    return true;
}

bool library::window::Window::Destroy(void) {
    if (!_handle) {
        return false;
    } // if
    ::glfwDestroyWindow(_handle);
    return true;
}

void library::window::Window::Close(void) const {
    ::glfwSetWindowShouldClose(_handle, 1);
}

void library::window::Window::Present(void) const {
    ::glfwSwapBuffers(_handle);
}

void library::window::Window::PollEvents(void) const {
    ::glfwPollEvents();
}