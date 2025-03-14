#pragma once

#include "../ECS/ECS.hpp"
#include "../Components/BoxColliderComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../EventManager/EventManager.hpp"
#include "../Events/CollisionEvent.hpp"
#include "../Logger/Logger.hpp"

class DamageSystem: public System {
public:
  DamageSystem() {
    require_component<BoxColliderComponent>();
    require_component<CollisionComponent>();
  }

  void ListenForEvents(std::unique_ptr<EventManager>& event_manager) {
    event_manager->listen_for_event(this, &DamageSystem::onCollision);
  }

  void onCollision(CollisionEvent& event) {
    Logger::Log("DamageSystem event occured! Entities: " + std::to_string(event.lhs.get_entity_id()) + " and " + std::to_string(event.rhs.get_entity_id()) + "!");
    event.lhs.get_component<CollisionComponent>().is_colliding = true;
    event.rhs.get_component<CollisionComponent>().is_colliding = true;
  }

  void Update() {
    // TODO:
  }
};
