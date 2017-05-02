#ifndef __ENGINE_INPUT__
#define __ENGINE_INPUT__

#include <vector>
#include <list>
#include <unordered_map>
#include <string>

#include "sdl2include.h"

namespace engine {

class InputManager {
public:
    InputManager();

    void gather_input(SDL_Event event);
    void clear_input();

    bool is_button_down(const std::string & button_name) const;
    bool is_button_up(const std::string & button_name) const;

private:
    std::unordered_map<std::string, SDL_Keycode> m_buttons;

    std::list<SDL_Event> m_updated;

    void create_keyboard_mapping();
    bool is_button_generic(const std::string & button_name,
                           unsigned int action_type) const;
};

}

#endif

