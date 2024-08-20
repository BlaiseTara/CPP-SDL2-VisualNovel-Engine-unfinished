#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "include/Text.h"
#include "include/graphics.h"
#include "include/rect.h"

void update() {
}

void render(Graphics graphics) {
  // Clear the screen with white
  SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 255);
  SDL_RenderClear(graphics.renderer);

  // Draw a rectangle
  DrawRect(graphics.renderer, 10, 10, 30, 30);

  // Update the screen
  SDL_RenderPresent(graphics.renderer);
}

int main(int argc, char *argv[]) {

  // Create a Graphics Object
  Graphics graphics;

  // Init Graphics
  if (graphics.Init() == 0) {
    return 0;
  }

  // Create a Window
  if (graphics.CreateWindow("Engine", 640, 480) == 0) {
    return 0;
  }

  // Create a Renderer
  if (graphics.CreateRenderer() == 0) {
    return 0;
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

      // Update things
      update();
      // Render things
      render(graphics);
    }
  }

  // Clean Up
  graphics.CleanUp();

  return 0;
}