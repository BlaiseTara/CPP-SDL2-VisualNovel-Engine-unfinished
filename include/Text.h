#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Text {

public:
  std::string text;
  Text(std::string Text, std::string FontPath, SDL_Renderer *Renderer);
  void render();

private:
  TTF_Font *font;
  SDL_Texture *texture;
  SDL_Renderer *renderer;
  SDL_Rect rect;
};

#endif