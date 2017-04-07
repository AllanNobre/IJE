#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "imagecomponent.hpp"

#include "gameglobals.hpp"

using namespace engine;

int main(int, char**)
{
    // Configure game
    Game::instance.set_properties(globals::game_name, globals::window_size);

    // Setup scenes
    Scene menu("Main Menu");
    Game::instance.add_scene(menu);

    GameObject playButton("Play Button");
    ImageComponent playButtonImage(playButton, "assets/sprites/playbutton.png");

    playButton.add_component(playButtonImage);
    menu.add_game_object(playButton);

    // Game loop
    Game::instance.run();

    return 0;
}
