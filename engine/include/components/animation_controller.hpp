#ifndef __ENGINE_COMPONENTS_ANIMATION_CONTROLLER__
#define __ENGINE_COMPONENTS_ANIMATION_CONTROLLER__

#include <string>
#include <unordered_map>

#include "components/component.hpp"
#include "components/animation.hpp"

namespace engine {

class AnimationControllerComponent : public Component {
public:
    AnimationControllerComponent()
        : Component(), current_animation(""), next_animation("") {}

    bool init();
    bool shutdown();
    void update();

    void add_animation(std::string name, AnimationComponent & animation);

    inline void play_animation(std::string name)
        { current_animation = name; }
    inline void play_animation_after_animation(std::string name)
        { next_animation = name; }

private:
    std::unordered_map<std::string, AnimationComponent *> m_animations_map;
    std::string current_animation;
    std::string next_animation;
};


}

#endif

