#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Graphics{
public:
  int Init();
  int CreateWindow(std::string Title, int Width, int Height);
  int CreateRenderer();
  void DrawRect(int x, int y, int w, int h, int r, int g, int b, int a);
  void CleanUp();
  SDL_Window *window;
  SDL_Renderer *renderer;
  
private:
};