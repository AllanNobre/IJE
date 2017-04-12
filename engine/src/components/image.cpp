#include "components/image.hpp"

#include "game.hpp"
#include "log.h"
#include "sdl_log.h"

using namespace engine;

bool ImageComponent::init()
{
    INFO("Init ImageComponent");

    if (m_path == "")
    {
        WARN("Invalid path for image!");
        return false;
    }

    SDL_Surface * image = IMG_Load(m_path.c_str());

    if (image == NULL)
    {
        SDL_IMG_ERROR("Could not load image from path " << m_path);
        return false;
    }

    m_texture = SDL_CreateTextureFromSurface(Game::instance.canvas(), image);

    if (m_texture == NULL)
    {
        SDL_ERROR("Could not create texture from image!");
        return false;
    }

    m_w = image->w;
    m_h = image->h;

    m_game_object->set_size(m_w, m_h);
    update_canvas_rect();

    m_image_rect.x = 0;
    m_image_rect.y = 0;
    m_image_rect.w = m_w;
    m_image_rect.h = m_h;

    SDL_FreeSurface(image);
    return true;
}

bool ImageComponent::shutdown()
{
    INFO("Shutdown ImageComponent");

    SDL_DestroyTexture(m_texture);
    m_texture = NULL;

    return true;
}

void ImageComponent::draw()
{
    update_canvas_rect();

    SDL_RenderCopy(Game::instance.canvas(), m_texture,
                   &m_image_rect, &m_canvas_rect);
}



void ImageComponent::update_canvas_rect()
{
    m_canvas_rect.x = m_game_object->x;
    m_canvas_rect.y = m_game_object->y;
    m_canvas_rect.w = m_game_object->w;
    m_canvas_rect.h = m_game_object->h;
}
