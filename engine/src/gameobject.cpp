#include "gameobject.hpp"

#include "log.h"

using namespace engine;

bool GameObject::init(SDL_Renderer *)
{
    INFO("Init game object " << m_name);

    return true;
}

bool GameObject::shutdown()
{
    INFO("Shutdown game object " << m_name);

    return true;
}

bool GameObject::draw(SDL_Renderer *)
{
    return true;
}
