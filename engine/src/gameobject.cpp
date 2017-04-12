#include "gameobject.hpp"

#include "components/animation.hpp"
#include "components/text.hpp"
#include "components/image.hpp"
#include "log.h"

using namespace engine;

bool GameObject::init()
{
    INFO("Init game object " << m_name);

    for(auto id_componentlist: m_components)
    {
        for (auto component: id_componentlist.second)
        {
            if(component->state() == Component::State::enabled &&
               component->init() == false) return false;
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
            if(component->state() == Component::State::enabled &&
               component->shutdown() == false) return false;
        }
    }

    return true;
}

template<typename T>
void GameObject::generic_draw()
{
    for(auto component: m_components[std::type_index(typeid(T))])
    {
        if(component->state() == Component::State::enabled)
            (dynamic_cast<T *>(component))->draw();
    }
}

void GameObject::draw()
{
    generic_draw<ImageComponent>();
    generic_draw<TextComponent>();
    generic_draw<AnimationComponent>();
}

bool GameObject::add_component(Component & component)
{
    INFO("Adding component to game object " << m_name);
    m_components[std::type_index(typeid(component))].push_back(&component);

    component.m_game_object = this;
    component.m_state = Component::State::enabled;

    return true;
}
