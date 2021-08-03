#include "GameApplication.h"


int main(int argc, char* argv[]) {
    auto framework = library::framework::Framework();
    auto application = std::make_shared<test::GameApplicaion>();

    auto window_create_info = library::window::WindowCreateInfomation();
    window_create_info.position_x = 0;
    window_create_info.position_y = 0;
    window_create_info.width = 1024;
    window_create_info.height= 768;
    bool success = framework.Setup(application, window_create_info);
    _ASSERT_EXPR(success, L"セットアップに失敗しました");

    auto result = framework.Run();
    
    
    framework.Cleanup();
    return result;
}