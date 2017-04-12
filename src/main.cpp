#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/text.hpp"
#include "components/animation.hpp"

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
    ImageComponent playButtonImage("assets/sprites/playbutton.png");
    TextComponent text("Bem Vindo!", "assets/fonts/font.ttf", 42);
    text.enable_high_quality();

    playButton.add_component(playButtonImage);
    playButton.add_component(text);

    GameObject boy("Boy");
    boy.set_position(200, 200);
    AnimationComponent boyAnimation("assets/sprites/boy.png", 8, 2, 1.0, true);
    boyAnimation.set_end_frame(7);
    //boyAnimation.set_frame_range(3, 9);

    menu.add_game_object(playButton);
    boy.add_component(boyAnimation);
    menu.add_game_object(boy);

    // Game loop
    Game::instance.run();

    return 0;
}
