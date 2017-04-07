#ifndef __ENGINE_COMPONENTS_IMAGE__
#define __ENGINE_COMPONENTS_IMAGE__

#include <string>
#include <utility>

#include "sdl2include.h"

#include "components/component.hpp"

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
