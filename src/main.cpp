#include "game.hpp"
#include "gameobject.hpp"
#include "scene.hpp"
#include "components/image.hpp"
#include "components/text.hpp"
#include "components/animation.hpp"
#include "components/animation_controller.hpp"
#include "components/audio.hpp"

#include "gameglobals.hpp"
#include "movesidetoside.hpp"

using namespace engine;

int main(int, char**)
{
    // Configure game
    Game::instance.set_properties(globals::game_name, globals::window_size);

    // Setup scenes
    Scene menu("Main Menu");
    Game::instance.add_scene(menu);

    GameObject playButton("Play Button");
    ImageComponent playButtonImage("playbutton.png");
    TextComponent text("Bem Vindo!", "font.ttf", 42);
    text.enable_high_quality();

    playButton.add_component(playButtonImage);
    playButton.add_component(text);

    GameObject boy("Boy");
    boy.set_position(200, 200);

    AnimationControllerComponent animCtrl;

    AnimationComponent boyAnimation("boy.png", 8, 2, 1.0, true);
    boyAnimation.set_end_frame(7);
    animCtrl.add_animation("running right", boyAnimation);

    AnimationComponent boyAnimation2("boy.png", 8, 2, 1.0, true);
    boyAnimation2.set_frame_range(8, 15);
    animCtrl.add_animation("running left", boyAnimation2);

    AudioComponent bgMusic("music.wav", true);

    MoveSideToSide movesidetoside;
    boy.add_component(movesidetoside);

    menu.add_game_object(playButton);
    boy.add_component(boyAnimation);
    boy.add_component(boyAnimation2);
    boy.add_component(animCtrl);
    boy.add_component(bgMusic);
    menu.add_game_object(boy);

    // Game loop
    Game::instance.run();

    return 0;
}
