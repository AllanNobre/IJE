#include "assets_manager.hpp"

#include "log.h"
#include "sdl_log.h"
#include "game.hpp"

using namespace engine;

bool AssetsManager::shutdown()
{
    INFO("Dealocate AssetsManager");

    INFO("Dealocate images");
    for(auto id_image: m_images)
    {
        SDL_DestroyTexture(id_image.second->texture);
        delete id_image.second;
    }
    m_images.clear();

    INFO("Dealocate fonts");
    for(auto id_font: m_fonts)
    {
        TTF_CloseFont(id_font.second);
    }
    m_fonts.clear();

    return true;
}

Image * AssetsManager::load_image(std::string path, bool use_base)
{
    if(use_base)
        path = m_base_path + "sprites/" + path;

    if (m_images.find(path) == m_images.end())
    {
        INFO("Loading new image...");

        SDL_Surface * image = IMG_Load(path.c_str());

        if (image == NULL)
        {
            SDL_IMG_ERROR("Could not load image from path " << path);
            return NULL;
        }

        auto m_texture = SDL_CreateTextureFromSurface(Game::instance.canvas(),
                                                      image);

        if (m_texture == NULL)
        {
            SDL_ERROR("Could not create texture from image!");
            return NULL;
        }

        Image * img = new Image;
        img->texture = m_texture;
        img->w = image->w;
        img->h = image->h;

        m_images[path] = img;

        SDL_FreeSurface(image);
    }

    return m_images[path];
}

TTF_Font * AssetsManager::load_font(std::string path, int size, bool use_base)
{
    if(use_base)
        path = m_base_path + "fonts/" + path;

    auto path_size = std::make_pair(path, size);

    if (m_fonts.find(path_size) == m_fonts.end())
    {
        INFO("Loading new font...");

        auto m_font = TTF_OpenFont(path.c_str(), size);

        if(m_font == NULL)
        {
            SDL_TTF_ERROR("Could not load font from path " << path);
            return NULL;
        }

        m_fonts[path_size] = m_font;
    }

    return m_fonts[path_size];
}
