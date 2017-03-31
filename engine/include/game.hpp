#ifndef __ENGINE_GAME__
#define __ENGINE_GAME__

#include <string>
#include <unordered_map>
#include <utility>

#include "sdl2include.h"

namespace engine {

class Game {
public:
    Game(std::string name, std::pair<int, int> window_size)
        : m_name(name), m_window_size(window_size),
          m_window(NULL), m_canvas(NULL),
          m_background_color({0xff, 0xff, 0xff, 0xff}) {}

    void run();
    void set_background_color(int r, int g, int b, int a);

private:
    std::string         m_name;
    std::pair<int, int> m_window_size;

    SDL_Window   * m_window;
    SDL_Renderer * m_canvas;
    SDL_Color      m_background_color;

    bool create_window();
    bool destroy_window();
};

}

#endif
