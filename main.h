#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "include/graphics.h"

Graphics graphics;
int fps;

void render();
void update();
int main();
