#ifndef __ENGINE_GAME_OBJECT__
#define __ENGINE_GAME_OBJECT__

#include <string>

#include "sdl2include.h"

namespace engine {

static const std::string INVALID_GAME_OBJECT_NAME = "INVALID_GAME_OBJECT";

class GameObject {
public:
    GameObject() : GameObject(INVALID_GAME_OBJECT_NAME) {}
    GameObject(std::string name)
        : x(0), y(0), w(0), h(0), rotation(0), m_name(name) {}

    virtual ~GameObject() {}

    virtual bool init(SDL_Renderer *);
    virtual bool shutdown();

    virtual bool draw(SDL_Renderer *);

    inline std::string name()  const { return m_name; }

    inline void set_size(int _w, int _h) { w = _w; h = _h; }

    int    x, y;
    int    w, h;
    double rotation;

private:
    std::string m_name;
};

// INVALID_GAME_OBJECT represents a not valid game object. Used in returns to
// represent an error instead of raising an exception.
static GameObject INVALID_GAME_OBJECT;

}

#endif
