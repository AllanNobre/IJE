#ifndef __PLAY_BUTTON__
#define __PLAY_BUTTON__

#include "gameobject.hpp"
#include "sdl2include.h"

class PlayButton : public engine::GameObject {
public:
    PlayButton() : engine::GameObject("PlayButton") {}

    ~PlayButton() {}

    virtual bool init();
    virtual bool shutdown();

    virtual bool draw();

private:
    SDL_Texture * m_texture;
};

#endif
