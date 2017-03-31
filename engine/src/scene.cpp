#include "scene.hpp"

#include "log.h"

using namespace engine;

bool Scene::init(SDL_Renderer *)
{
    INFO("Init scene " << m_name);
    return true;
}

bool Scene::shutdown()
{
    INFO("Shutdown scene " << m_name);
    return true;
}

bool Scene::draw(SDL_Renderer *)
{
    return true;
}
