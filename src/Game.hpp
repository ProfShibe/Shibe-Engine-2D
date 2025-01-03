#pragma once

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_image.h>

const int8_t FPS = 60;
const Uint16 MS_PER_FRAME = 1000 / FPS;
const int8_t DEFAULT_MONITOR_NUMBER = -1;

class Game {
public:
  Game();
  ~Game();
  void Initialize();
  void Run();
  void Setup();
  void ProcessInput();
  void Update();
  void Render();
  void Destroy();

  Uint16 WIDTH;
  Uint16 HEIGHT;
  bool is_running;

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  unsigned int ms_previous_frame = 0;
};
