#include "rect.h"

void DrawRect(SDL_Renderer* renderer, int x, int y, int w, int h){
  // Define the rectangle
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  // Draw the rectangle
  SDL_RenderFillRect(renderer, &rect);
}