#include "gameobject.hpp"

#include "log.h"

using namespace engine;

bool GameObject::init()
{
    INFO("Init game object " << m_name);

    return true;
}

bool GameObject::shutdown()
{
    INFO("Shutdown game object " << m_name);

    return true;
}

bool GameObject::draw()
{
    return true;
}
