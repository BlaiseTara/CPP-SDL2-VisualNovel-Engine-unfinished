#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "includes/rect.h"

void render() {}

void update() {}

int main(int argc, char *argv[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 1;
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
  std::cout << "Program Started!" << std::endl;

  SDL_Texture *img = NULL;
  int w, h; // texture width & height

  // load our image
  img = IMG_LoadTexture(renderer, "Images/bg.png");
  SDL_QueryTexture(img, NULL, NULL, &w,
                   &h); // get the width and height of the texture
  // put the location where we want the texture to be drawn into a rectangle
  // I'm also scaling the texture 2x simply by setting the width and height
  SDL_Rect texr;
  texr.x = 0;
  texr.y = 0;
  texr.w = 640;
  texr.h = 480;

  unsigned int a = SDL_GetTicks();
  unsigned int b = SDL_GetTicks();
  double delta = 0;

  // Main Loop
  while (true) {
    a = SDL_GetTicks();
    delta = a - b;

    if (delta > 1000 / 60.0) {

      std::cout << "fps: " << 1000 / delta << std::endl;

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

      // copy the texture to the rendering context
      SDL_RenderCopy(renderer, img, NULL, &texr);

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