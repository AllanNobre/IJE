#include "game.hpp"
#include "scene.hpp"

#include "gameglobals.hpp"
#include "playbutton.hpp"

using namespace engine;

int main(int, char**)
{
    Game::instance.set_properties(globals::game_name, globals::window_size);

    Scene menuScene("Menu");
    PlayButton playButton;
    playButton.x = 10;
    playButton.y = 10;
    menuScene.add_game_object(playButton);

    Game::instance.add_scene(menuScene);

    Game::instance.run();

    return 0;
}
