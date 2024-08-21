#include "main.h"

void update() {}

void render() {
  // Clear the screen with white
  SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 255, 255);
  SDL_RenderClear(graphics.renderer);

  // Get Window Dimensions
  int width = 0;
  int height = 0;
  SDL_GetWindowSize(graphics.window, &width, &height);

  // Draw images and charcters here

  // Draw the Dialog Box
  graphics.DrawRect(20, height - 150, width - 40, 140, 100, 100, 100, 100);

  // Draw the Dialog Text
  graphics.DrawText("This is some test text for the line wrapping. this is a very long sentence...", 50, 50, 25, 200, 0, 0, 0, 255);

  // Draw the FPS
  graphics.DrawText("FPS: " + std::to_string(fps), 10, 10, 17, 200, 0, 0, 0, 255);

  // Update the screen
  SDL_RenderPresent(graphics.renderer);
}

int main() {
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

  std::cout << "Program Started!" << std::endl;

  unsigned int newTime = 0;
  unsigned int oldTime = 0;
  unsigned int delta = 0;

  // Main Loop
  while (true) {
    newTime = SDL_GetTicks();
    delta = newTime - oldTime;

    if (delta > 1000 / 60.0) {

      // std::cout << "fps: " << 1000 / delta << std::endl;
      oldTime = newTime;
      fps = 1000 / delta;

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
      render();
    }
  }

  // Clean Up
  graphics.CleanUp();

  return 0;
}