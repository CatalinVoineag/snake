#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Window.h"
#include "UI.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);
  Window GameWindow;
  UI UIManager;

  Uint32 OPEN_SETTINGS{SDL_RegisterEvents(1)};
  SDL_Event MyEvent{ .type = OPEN_SETTINGS };
  SDL_PushEvent(&MyEvent);

  bool IsRunning = true;
  SDL_Event Event;
  while (IsRunning) {
    while (SDL_PollEvent(&Event)) {
      UIManager.HandleEvent(Event);
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      } else if (Event.type == OPEN_SETTINGS) {
        std::cout << "Open settings\n";
      }
    }

    GameWindow.Render();
    UIManager.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  SDL_Quit();
  return 0;
}
