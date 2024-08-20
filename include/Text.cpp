#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "Text.h"

Text::Text(std::string Text, std::string FontPath, SDL_Renderer *Renderer,
           int xPos, int yPos, int FontSize) {
  text = Text;
  font = TTF_OpenFont(FontPath.c_str(), FontSize);
  renderer = Renderer;
  SDL_Color COLOR = {0, 0, 0};
  SDL_Surface *surface = TTF_RenderText_Solid(font, Text.c_str(), COLOR);

  texture = SDL_CreateTextureFromSurface(renderer, surface);

  rect.x = xPos;
  rect.y = yPos;
  rect.w = surface->w;
  rect.h = surface->h;

  SDL_FreeSurface(surface);
}

void Text::render() {
  // Copys the text onto the Renderer
  SDL_RenderCopy(renderer, texture, NULL, &rect);
}