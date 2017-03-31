#include "menuscene.hpp"

#include "log.h"
#include "sdl_log.h"

bool MenuScene::init(SDL_Renderer * canvas)
{
    engine::Scene::init(canvas);

    // ===== Load Texture =====
    INFO("Load Texture");

    SDL_Surface * image = NULL;
    image = IMG_Load("assets/sprites/playbutton.png");

    if (image == NULL)
    {
        SDL_IMG_ERROR("Can't load sprite");
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(canvas, image);

    if (m_texture == NULL)
    {
        SDL_ERROR("Can't create texture from image");
        return false;
    }

    m_w = image->w;
    m_h = image->h;

    SDL_FreeSurface(image);
    image = NULL;

    return true;
}

bool MenuScene::shutdown()
{
    engine::Scene::shutdown();

    INFO("Destroy texture");
    SDL_DestroyTexture(m_texture);
    m_texture = NULL;

    return true;
}

bool MenuScene::draw(SDL_Renderer * canvas)
{
    SDL_Rect renderQuad = {10, 10, m_w, m_h};
    SDL_RenderCopy(canvas, m_texture, NULL, &renderQuad);

    return true;
}
