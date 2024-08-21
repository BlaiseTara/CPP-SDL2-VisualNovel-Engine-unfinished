#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

class Graphics {
public:
  SDL_Window *window;
  SDL_Renderer *renderer;
  TTF_Font *Font;

  int Init();
  int CreateWindow(std::string Title, int Width, int Height);
  int CreateRenderer();
  void DrawRect(int x, int y, int w, int h, int r, int g, int b, int a);
  void DrawText(std::string Text, int x, int y, int size, uint32_t wrapLength,
                uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  void CleanUp();

private:
};