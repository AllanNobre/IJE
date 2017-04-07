#ifndef __PLAY_BUTTON__
#define __PLAY_BUTTON__

#include "gameobject.hpp"

class PlayButton : public engine::GameObject {
public:
    PlayButton() : engine::GameObject("PlayButton") {}

    ~PlayButton() {}

    virtual bool init(SDL_Renderer *);
    virtual bool shutdown();

    virtual bool draw(SDL_Renderer *);

private:
    SDL_Texture * m_texture;
};

#endif
