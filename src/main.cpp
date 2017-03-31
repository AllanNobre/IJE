#include "sdl2include.h"
#include "log.h"
#include "sdl_log.h"

int main(int, char**)
{
    // ===== Init dependencies =====
    INFO("Init dependencies");

    INFO("Init sdl");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        SDL_ERROR("Could not initialize video or audio");
        std::exit(EXIT_FAILURE);
    }

    INFO("Init sdl image");
    int img_flags = IMG_INIT_PNG;
    if(!(IMG_Init(img_flags) & img_flags))
    {
        SDL_IMG_ERROR("Could not initialize sdl image");
        std::exit(EXIT_FAILURE);
    }



    // ===== Create Window and Canvas =====

    INFO("Create Window");
    SDL_Window * window = SDL_CreateWindow(
        "Prince Rescue",        // Title
        SDL_WINDOWPOS_CENTERED, // Position x. SDL_WINDOWPOS_UNDEFINED
        SDL_WINDOWPOS_CENTERED, // Position y. SDL_WINDOWPOS_UNDEFINED
        400,                    // width
        400,                    // height
        SDL_WINDOW_SHOWN        // Window flags, SDL_WindowFlags for more
    );

    if (window == NULL)
    {
        SDL_ERROR("Could not create window");
        std::exit(EXIT_FAILURE);
    }

    INFO("Create canvas");
    SDL_Renderer * canvas = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (canvas == NULL)
    {
        SDL_ERROR("Could not create canvas");
        std::exit(EXIT_FAILURE);
    }

    SDL_SetRenderDrawColor(canvas, 0xff, 0xff, 0xff, 0xff); // White


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

    play_button_texture = SDL_CreateTextureFromSurface(canvas, image);

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

    INFO("Game Loop: START");
    bool close_game = false;

    while(!close_game)
    {
        // Read Input
        SDL_Event evt;
        while(SDL_PollEvent(&evt) != 0)
        {
            if (evt.type == SDL_QUIT)
                close_game = true;
        }

        // Draw
        SDL_RenderClear(canvas);

        SDL_Rect renderQuad = {10, 10, play_button_w, play_button_h};
        SDL_RenderCopy(canvas, play_button_texture, NULL, &renderQuad);

        SDL_RenderPresent(canvas);
    }

    INFO("Game Loop: END");



    // ===== Shutdown =====

    INFO("Shutdown");

    INFO("Destroy texture");
    SDL_DestroyTexture(play_button_texture);
    play_button_texture = NULL;

    INFO("Destroy canvas");
    SDL_DestroyRenderer(canvas);
    canvas = NULL;

    INFO("Destroy window");
    SDL_DestroyWindow(window);
    window = NULL;

    INFO("Quit IMG");
    IMG_Quit();
    INFO("Quit SDL");
    SDL_Quit();

    return 0;
}
