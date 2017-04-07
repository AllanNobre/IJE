#ifndef __ENGINE_GAME_OBJECT__
#define __ENGINE_GAME_OBJECT__

#include <string>
#include <list>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include "component.hpp"
#include "imagecomponent.hpp"

namespace engine {

class GameObject {
public:
    enum class State {
        enabled,
        disabled,
        invalid
    };

    GameObject() : GameObject("", State::invalid) {}
    GameObject(std::string name, State state=State::enabled)
        : x(0), y(0), w(0), h(0), rotation(0), m_name(name),
          m_state(state) {}

    virtual ~GameObject() {}

    virtual bool init();
    virtual bool shutdown();

    virtual bool draw();

    bool add_component(Component & component);

    inline std::string name()  const { return m_name; }
    inline State       state() const { return m_state; }

    inline void set_size(int _w, int _h) { w = _w; h = _h; }

    int    x, y;
    int    w, h;
    double rotation;

private:
    std::string m_name;
    State       m_state;
    std::unordered_map<std::type_index, std::list<Component *> > m_components;
};

}

#endif
