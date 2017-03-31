#include "game.hpp"

#include "log.h"
#include "sdl_log.h"

using namespace engine;

bool setup_sdl()
{
    INFO("Setup SDL");

    INFO("Init video and audio");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_ERROR("SDL_Init");
        return false;
    }

    INFO("Init image png");
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
    {
        SDL_IMG_ERROR("IMG_Init");
        return false;
    }

    return true;
}

bool Game::create_window()
{
    INFO("Create Window (" << m_name << ", " << m_window_size.first << ", " <<
         m_window_size.second << ")");

    m_window = SDL_CreateWindow(
        m_name.c_str(),         // Title
        SDL_WINDOWPOS_CENTERED, // Position x. SDL_WINDOWPOS_UNDEFINED
        SDL_WINDOWPOS_CENTERED, // Position y. SDL_WINDOWPOS_UNDEFINED
        m_window_size.first,    // width
        m_window_size.second,   // height
        SDL_WINDOW_SHOWN        // Window flags, SDL_WindowFlags for more
    );

    if (m_window == NULL)
    {
        SDL_ERROR("SDL_CreateWindow");
        return false;
    }

    INFO("Create canvas");
    m_canvas = SDL_CreateRenderer(
        m_window,
        -1, // Render driver. -1 to the first one that support the flags
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (m_canvas == NULL)
    {
        SDL_ERROR("SDL_CreateRenderer");
        return false;
    }

    SDL_SetRenderDrawColor(m_canvas,
                           m_background_color.r, m_background_color.b,
                           m_background_color.g, m_background_color.a);

    return true;
}

bool teardown_sdl()
{
    INFO("Teardown SDL");

    INFO("Quit SDL IMG");
    IMG_Quit();

    INFO("Quit SDL");
    SDL_Quit();

    return true;
}

bool Game::destroy_window()
{
    INFO("Destroy canvas");
    SDL_DestroyRenderer(m_canvas);
    m_canvas = NULL;

    INFO("Destroy window");
    SDL_DestroyWindow(m_window);
    m_window = NULL;

    return true;
}

void Game::run()
{
    INFO("Game " << m_name << "Setup");

    if (setup_sdl() && create_window())
    {
        INFO("Start game loop");

        // ===== Load Texture =====
        INFO("Load Texture");
        SDL_Texture * play_button_texture = NULL;

        SDL_Surface * image = NULL;
        image = IMG_Load("assets/sprites/playbutton.png");

        if (image == NULL)
        {
            SDL_IMG_ERROR("Can't load sprite");
            std::exit(EXIT_FAILURE);
        }

        play_button_texture = SDL_CreateTextureFromSurface(m_canvas, image);

        if (play_button_texture == NULL)
        {
            SDL_ERROR("Can't create texture from image");
            std::exit(EXIT_FAILURE);
        }

        int play_button_w = image->w;
        int play_button_h = image->h;

        SDL_FreeSurface(image);
        image = NULL;

        // ===== Main Loop =====
        bool close_game = false;
        while(!close_game)
        {
            SDL_Event evt;
            while(SDL_PollEvent(&evt) != 0)
            {
                if (evt.type == SDL_QUIT) close_game = true;
            }

            SDL_RenderClear(m_canvas);

            SDL_Rect renderQuad = {10, 10, play_button_w, play_button_h};
            SDL_RenderCopy(m_canvas, play_button_texture, NULL, &renderQuad);

            SDL_RenderPresent(m_canvas);
        }

        INFO("Cleaning up resources...");

        INFO("Destroy texture");
        SDL_DestroyTexture(play_button_texture);
        play_button_texture = NULL;
    }

    INFO("Game Shutdown");
    destroy_window();
    teardown_sdl();
}

void Game::set_background_color(int r, int g, int b, int a)
{
    m_background_color.r = r;
    m_background_color.g = g;
    m_background_color.b = b;
    m_background_color.a = a;

    if (m_canvas != NULL)
    {
        SDL_SetRenderDrawColor(m_canvas,
                               m_background_color.r, m_background_color.b,
                               m_background_color.g, m_background_color.a);
    }
}
