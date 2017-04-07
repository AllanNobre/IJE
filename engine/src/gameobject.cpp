
#include "gameobject.hpp"

#include "log.h"

using namespace engine;

bool GameObject::init()
{
    INFO("Init game object " << m_name);

    for(auto id_componentlist: m_components)
    {
        for (auto component: id_componentlist.second)
        {
            if(component->init() == false) return false;
        }
    }

    return true;
}

bool GameObject::shutdown()
{
    INFO("Shutdown game object " << m_name);

    for(auto id_componentlist: m_components)
    {
        for (auto component: id_componentlist.second)
        {
            if(component->shutdown() == false) return false;
        }
    }

    return true;
}

bool GameObject::draw()
{
    for(auto component: m_components[std::type_index(typeid(ImageComponent))])
    {
        (dynamic_cast<ImageComponent *>(component))->draw();
    }

    return true;
}

bool GameObject::add_component(Component & component)
{
    INFO("Adding component to game object " << m_name);
    m_components[std::type_index(typeid(component))].push_back(&component);

    return true;
}

