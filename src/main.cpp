#include "game.hpp"

#include "gameglobals.hpp"

using namespace engine;

int main(int, char**)
{
    Game::instance.set_properties(globals::game_name, globals::window_size);

    Scene menuScene("Menu");
    GameObject playButton("PlayButton");
    playButton.x = 10;
    playButton.y = 10;

    ImageComponent playButtonImage(playButton, "assets/sprites/playbutton.png");
    playButton.add_component(playButtonImage);

    menuScene.add_game_object(playButton);

    Game::instance.add_scene(menuScene);

    Game::instance.run();

    return 0;
}
