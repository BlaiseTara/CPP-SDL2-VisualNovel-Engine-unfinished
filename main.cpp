#include "main.h"

void update() {
  
}

void render() {
  // Get Byte
  graphics.DrawText(std::to_string(ReadBinaryByte(LineCounter)), 10, 10, 20, 100, 255, 0, 0, 255);

  // Update the screen
  SDL_RenderPresent(graphics.renderer);
}

int main(int argc, char* argv[]) {
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
  LineCounter = 0;

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