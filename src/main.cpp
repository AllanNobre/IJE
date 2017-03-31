#include "game.hpp"

#include "gameglobals.hpp"

using namespace engine;

int main(int, char**)
{
    Game game(globals::game_name, globals::window_size);

    game.run();

    return 0;
}
