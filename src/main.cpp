#include "game.hpp"

#include "gameglobals.hpp"
#include "menuscene.hpp"
#include "gameplayscene.hpp"

using namespace engine;

int main(int, char**)
{
    Game game(globals::game_name, globals::window_size);

    MenuScene menu_scene;
    game.add_scene(menu_scene);

    game.run();

    return 0;
}
