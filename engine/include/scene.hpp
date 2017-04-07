#ifndef __ENGINE_SCENE__
#define __ENGINE_SCENE__

#include <string>
#include <unordered_map>

#include "gameobject.hpp"

namespace engine {

static const std::string INVALID_SCENE_NAME = "INVALID_SCENE";

class Scene {
public:
    Scene(std::string name=INVALID_SCENE_NAME)
        : m_name(name) {}

    virtual ~Scene() {}

    bool add_game_object(GameObject & obj);
    GameObject & get_game_object(const std::string & id);
    bool remove_game_object(const std::string & id);

    virtual bool init();
    virtual bool shutdown();

    virtual bool draw();

    inline std::string name() const { return m_name; }

protected:
    std::string m_name;
    std::unordered_map<std::string, GameObject *> m_objects;
};

}

#endif
