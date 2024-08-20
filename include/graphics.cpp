#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

// Make a class instead?
int GraphicsInit() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 0;
  }
  if (TTF_Init() < 0) {
    std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    return 0;
  }
  return 1;
}