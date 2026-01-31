#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "Rectangle.h"
#include "UserEvents.h"

class Button : public Rectangle {
 public:
  Button(const SDL_Rect& Rect)
  : Rectangle{Rect}
  {
    SetColor({255, 165, 0, 255});
  }

  void HandleEvent(SDL_Event& E) {
    Rectangle::HandleEvent(E);
    using namespace UserEvents;
    if (E.type == CLOSE_SETTINGS) {
      isSettingsOpen = false;
    } else if (E.type == OPEN_SETTINGS) {
      isSettingsOpen = true;
    }
  }

  void OnLeftClick() override {
    using namespace UserEvents;
    SDL_Event Event{ 
      .type = isSettingsOpen ? CLOSE_SETTINGS : OPEN_SETTINGS
    };

    if (Event.type == OPEN_SETTINGS) {
      Event.user.data1 = this;
    }

    SDL_PushEvent(&Event);
  }

  UserEvents::SettingsConfig GetConfig() {
    return Config;
  }

  std::string GetLocation() {
    return "the main menu";
  }

private:
  UserEvents::SettingsConfig Config{
    UserEvents::SettingsPage::GAMEPLAY,
    50, 100
  };
  bool isSettingsOpen{false};
};
