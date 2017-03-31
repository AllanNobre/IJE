#ifndef __MENU_SCENE__
#define __MENU_SCENE__

#include "scene.hpp"

class MenuScene : public engine::Scene {
public:
    MenuScene() : engine::Scene("Menu") {}

    ~MenuScene() {}

    bool init(SDL_Renderer * canvas);
    bool shutdown();

    bool draw(SDL_Renderer * canvas);
};

#endif
