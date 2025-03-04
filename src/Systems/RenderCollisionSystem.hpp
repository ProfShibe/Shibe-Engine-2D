#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include "../ECS/ECS.hpp"
#include "../Components/BoxColliderComponent.hpp"
#include "../Components/TransformComponent.hpp"

class RenderCollisionSystem : public System {
  public:
    RenderCollisionSystem() {
      require_component<BoxColliderComponent>();
      require_component<TransformComponent>();
  }
   ~RenderCollisionSystem() = default;

  void Update(SDL_Renderer* renderer) {
    for (auto& entity: get_system_entities()) {
      auto& collider = entity.get_component<BoxColliderComponent>();
      auto& transform = entity.get_component<TransformComponent>();

      SDL_Rect rect {
        static_cast<int>(transform.position.x + collider.offset.x),
        static_cast<int>(transform.position.y + collider.offset.y),
        static_cast<int>(collider.width),
        static_cast<int>(collider.height)
      };

      // FIXME: This is drawing red still after entities that collided
      // are removed, AND it draws red for ALL entities with a BoxColliderComponent
      // 2025-03-01 13:27
      // logic itself works, issue is elsewhere
      if (entity.is_colliding) // draw red if colliding
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
      else // else draw yellow
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

      SDL_RenderDrawRect(renderer, &rect);
    }
  }

};
