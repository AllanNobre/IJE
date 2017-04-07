#include "game.hpp"
#include "scene.hpp"

#include "gameglobals.hpp"
#include "playbutton.hpp"

using namespace engine;

int main(int, char**)
{
    Game game(globals::game_name, globals::window_size);

    Scene menuScene("Menu");
    PlayButton playButton;
    playButton.x = 10;
    playButton.y = 10;
    menuScene.add_game_object(playButton);

    game.add_scene(menuScene);

    game.run();

    return 0;
}
