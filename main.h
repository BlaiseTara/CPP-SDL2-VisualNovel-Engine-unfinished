#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

#include "include/graphics.h"
#include "include/interpreter.h"

Graphics graphics;
int fps;
int LineCounter;

int main(int argv, char** args);

void update();
void render();