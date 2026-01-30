#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

int main(int, char**) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* Window{SDL_CreateWindow(
    "Hello Window", 800, 300, 0
  )};

  SDL_Renderer* Renderer = SDL_CreateRenderer(Window, NULL);

  SDL_SetRenderDrawColor(Renderer, 30, 30, 60, 255);
  SDL_RenderClear(Renderer);
  SDL_RenderPresent(Renderer);

  bool IsRunning = true;
  SDL_Event Event;
  while (IsRunning) {
    while (SDL_PollEvent(&Event)) {
      if (Event.type == SDL_EVENT_QUIT) {
        IsRunning = false;
      }
    }
  }

  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit();

  return 0;
}
