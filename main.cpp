#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "include/Text.h"
#include "include/graphics.h"
#include "include/rect.h"

void render() {}

void update() {}

int main(int argc, char *argv[]) {

  // Init Graphics
  if (GraphicsInit() == 0) {
    return 0;
  }

  // Create a window
  SDL_Window *window =
      SDL_CreateWindow("SDL Rectangle", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_Quit();
    return 1;
  }

  // Create a renderer
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr) {
    std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Init all vars

  // std::vector<Text> text;
  // text.push_back(Text("HI1", "fonts/Sans.ttf", renderer, 50, 50, 25));

  std::cout << "Program Started!" << std::endl;

  unsigned int a = SDL_GetTicks();
  unsigned int b = SDL_GetTicks();
  double delta = 0;

  // Main Loop
  while (true) {
    a = SDL_GetTicks();
    delta = a - b;

    if (delta > 1000 / 60.0) {

      // std::cout << "fps: " << 1000 / delta << std::endl;

      b = a;

      // Get the next event
      SDL_Event event;
      if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          break;
        }
      }

      // Render things

      // Clear the screen with white
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      SDL_RenderClear(renderer);

      // Draw a rectangle
      DrawRect(renderer, 10, 10, 30, 30);

      // Update the screen
      SDL_RenderPresent(renderer);
    }
  }

  // Clean up
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}