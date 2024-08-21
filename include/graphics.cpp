#include "graphics.h"

int Graphics::Init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 0;
  }
  // Initialize Fonts
  if (TTF_Init() < 0) {
    std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
    return 0;
  }
  // Load a font
  Font = TTF_OpenFont("fonts/Sans.ttf", 30);
  return 1;
}

int Graphics::CreateWindow(std::string Title, int Width, int Height) {
  // Create a window
  window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, Width, Height,
                            SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_Quit();
    return 0;
  }
  return 1;
}

int Graphics::CreateRenderer() {
  // Create a renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

  if (renderer == nullptr) {
    std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
  }
  return 1;
}

void Graphics::DrawRect(int x, int y, int w, int h, int r, int g, int b,
                        int a) {
  // Define the rectangle
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  // Set Color
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
  // Draw the rectangle
  SDL_RenderFillRect(renderer, &rect);
}

void Graphics::DrawText(std::string text, int x, int y, int size, uint8_t r,
                        uint8_t g, uint8_t b, uint8_t a) {
  TTF_SetFontSize(Font, size);
  SDL_Color TextColor = {r, g, b, a};
  SDL_Surface *TextSurface =
      TTF_RenderText_Solid(Font, text.c_str(), TextColor);

  SDL_Texture *TextTexture =
      SDL_CreateTextureFromSurface(renderer, TextSurface);

  SDL_Rect TextRect;

  TextRect.x = x;
  TextRect.y = y;
  TextRect.w = TextSurface->w;
  TextRect.h = TextSurface->h;

  SDL_FreeSurface(TextSurface);
  SDL_RenderCopy(renderer, TextTexture, NULL, &TextRect);
  SDL_DestroyTexture(TextTexture);
}

void Graphics::CleanUp() {
  // Clean up
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}