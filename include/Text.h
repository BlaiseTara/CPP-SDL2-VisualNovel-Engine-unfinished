#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Text {

public:
  Text(std::string Text, std::string FontPath, SDL_Renderer *Renderer, int xPos, int yPos, int FontSize);
  void render();

private:
  std::string text;
  TTF_Font *font;
  SDL_Texture *texture;
  SDL_Renderer *renderer;
  SDL_Rect rect;
};
