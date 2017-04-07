#ifndef __ENGINE_IMAGE_COMPONENT__
#define __ENGINE_IMAGE_COMPONENT__

#include <string>
#include <utility>

#include "sdl2include.h"

#include "component.hpp"

namespace engine {

class ImageComponent : public Component {
public:
    ImageComponent(GameObject & game_object, std::string path)
        : Component(game_object), m_path(path) {}

    ~ImageComponent() {}

    bool init();
    bool shutdown();

    void draw();

private:
    std::string m_path;

    SDL_Texture * m_texture;
};

}

#endif
