#ifndef __ENGINE_COMPONENT__
#define __ENGINE_COMPONENT__

namespace engine {

class GameObject;

class Component {
public:
    Component() : m_game_object(NULL) {}
    Component(GameObject & game_object)
        : m_game_object(&game_object) {}

    virtual ~Component() {}

    virtual bool init() { return true; }
    virtual bool shutdown() { return true; }

protected:
    GameObject * m_game_object;
};

}

#endif
