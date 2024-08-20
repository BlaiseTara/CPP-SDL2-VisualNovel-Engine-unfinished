#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Graphics{
public:
  int Init();
  int CreateWindow(std::string Title, int Width, int Height);
  int CreateRenderer();
  void CleanUp();
  SDL_Window *window;
  SDL_Renderer *renderer;
  
private:
};

#endif