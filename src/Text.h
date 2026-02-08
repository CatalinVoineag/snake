#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include <iostream>

class Text {
 public:
  Text(const std::string& Content, float Size = 25.0f) : Font{
    TTF_OpenFont("Roboto-Medium.ttf", Size)
  } {
    if (!Font) {
      std::cout << "Error font: " << SDL_GetError() << '\n';
    }

    CreateSurface(Content);
  }

  void SetFontSize(float NewSize) {
    TTF_SetFontSize(Font, NewSize);
  }

  void Render(SDL_Surface* DestinationSurface) {
    if (!TextSurface) return;
    SDL_BlitSurface(
      TextSurface, nullptr,
      DestinationSurface, &DestinationRectangle
    );
  }

 ~Text() {
   SDL_DestroySurface(TextSurface);
   if (TTF_WasInit()) {
     TTF_CloseFont(Font);
   }
 } 

 Text(const Text&) = delete;
 Text& operator=(const Text&) = delete;

  void CreateSurface(const std::string& Content) {
    SDL_Surface* newSurface{TTF_RenderText_LCD(
      Font,
      Content.c_str(),
      0,
      {255, 255, 255, 255},
      {0, 0, 90, 255}
    )};
    if (newSurface) {
      SDL_DestroySurface(TextSurface);
      TextSurface = newSurface;
    } else {
      std::cout << "Error text surface: " << SDL_GetError() << '\n';
    }
  }

  TTF_Font* Font{nullptr};
  SDL_Surface* TextSurface;
private:
  SDL_Rect DestinationRectangle{0, 0, 0, 0};
};
