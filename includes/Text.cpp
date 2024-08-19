#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Text.h"

Text::Text(std::string Text, std::string FontPath, SDL_Renderer *Renderer) {
  text = Text;
  font = TTF_OpenFont(FontPath.c_str(), 24);
  renderer = Renderer;
  SDL_Color COLOR = {255, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Solid(font, Text.c_str(), COLOR);

  texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_FreeSurface(surface);

  rect.x = 10;
  rect.y = 10;
  rect.w = 100;
  rect.h = 50;
}

void Text::render(){
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}