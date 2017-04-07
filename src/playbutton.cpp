#include "playbutton.hpp"

#include "game.hpp"
#include "log.h"
#include "sdl_log.h"

bool PlayButton::init()
{
    engine::GameObject::init();

    // ===== Load Texture =====
    INFO("Load Texture");

    SDL_Surface * image = NULL;
    image = IMG_Load("assets/sprites/playbutton.png");

    if (image == NULL)
    {
        SDL_IMG_ERROR("Can't load sprite");
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(engine::Game::instance.canvas(),
                                             image);

    if (m_texture == NULL)
    {
        SDL_ERROR("Can't create texture from image");
        return false;
    }

    w = image->w;
    h = image->h;

    SDL_FreeSurface(image);
    image = NULL;

    return true;
}

bool PlayButton::shutdown()
{
    engine::GameObject::shutdown();

    INFO("Destroy texture");
    SDL_DestroyTexture(m_texture);
    m_texture = NULL;

    return true;
}

bool PlayButton::draw()
{
    SDL_Rect renderQuad = {x, y, w, h};
    SDL_RenderCopy(engine::Game::instance.canvas(), m_texture, NULL, &renderQuad);

    return true;
}
