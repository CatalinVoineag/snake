#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Window.h"
#include "UI.h"
#include "Text.h"
#include "ScaledText.h"
#include "TruncatedText.h"
#include "WrappedText.h"

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);
  if (!TTF_Init()) {
    std::cout << "Error with ttf " << SDL_GetError();
  }
  Window GameWindow;
  WrappedText TextExample{
    "The quick brown fox jumps over the lazy dog",
    50.0f,
    GameWindow.GetWidth()
  };
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
    // UIManager.Render(GameWindow.GetSurface());
    // Example.Render(GameWindow.GetSurface());
    TextExample.Render(GameWindow.GetSurface());
    GameWindow.Update();
  }

  TTF_Quit();
  SDL_Quit();
  return 0;
}
