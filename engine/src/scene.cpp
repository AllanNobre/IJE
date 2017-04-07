#include "scene.hpp"

#include "log.h"

using namespace engine;

bool Scene::add_game_object(GameObject & obj)
{
    auto id = obj.name();
    INFO("Add game object " << id << " to scene " << m_name);

    if (m_objects.find(id) != m_objects.end())
    {
        WARN("Game object " << id << " already exists!");
        return false;
    }

    m_objects[id] = &obj;
    return true;
}

GameObject & Scene::get_game_object(const std::string & id)
{
    if (m_objects.find(id) == m_objects.end())
    {
        WARN("Could not find game object " << id);
        return INVALID_GAME_OBJECT;
    }

    return *m_objects[id];
}

bool Scene::remove_game_object(const std::string & id)
{
    INFO("Remove game object " << id << " from scene " << m_name);

    if (m_objects.find(id) == m_objects.end())
    {
        WARN("Could not find game object " << id);
        return false;
    }

    m_objects.erase(id);
    return true;
}

bool Scene::init(SDL_Renderer * canvas)
{
    INFO("Init scene " << m_name);

    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->init(canvas) == false) return false;
    }

    return true;
}

bool Scene::shutdown()
{
    INFO("Shutdown scene " << m_name);

    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->shutdown() == false) return false;
    }

    return true;
}

bool Scene::draw(SDL_Renderer * canvas)
{
    for (auto id_obj: m_objects)
    {
        auto obj = id_obj.second;
        if (obj->draw(canvas) == false) return false;
    }

    return true;
}
