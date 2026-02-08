#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Window {
public:
  Window() {
    SDLWindow = SDL_CreateWindow(
      "Hello Window",
      1200, 800, 0
    );
  }

  int GetWidth() {
    return 800;
  }

  void TakeScreenshot() const {
    IMG_SaveJPG(
      GetSurface(), "Screenshot.jpg", 90
    );
  }

  void Render() {
    const auto* Fmt = SDL_GetPixelFormatDetails(
      GetSurface()->format
    );

    SDL_FillSurfaceRect(
      GetSurface(),
      nullptr,
      SDL_MapRGB(Fmt, nullptr, 50, 50, 50)
    );
  }

  void Update() {
    SDL_UpdateWindowSurface(SDLWindow);
  }

  SDL_Surface* GetSurface() const {
    return SDL_GetWindowSurface(SDLWindow);
  }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;
  ~Window() {
    if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO)) {
      SDL_DestroyWindow(SDLWindow);
    }
  }

private:
  SDL_Window* SDLWindow{nullptr};
};
