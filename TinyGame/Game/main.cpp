#include "GameApplication.h"


int main(int argc, char* argv[]) {
    auto game = game::GameApplication();
    game.Initialize();
    while (true) 	{
        game.Update(0.01667f);
    } // while
    game.Release();
    return 0;
}