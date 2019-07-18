#include <SDL2/SDL.h>
#include "car.h"
#include "imgtexture.h"

// Prototypes
void input();
void update();
void draw(SDL_Renderer *, SDL_Texture *);

// Constants
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;

// Other globals
bool running = true;

bool leftPress = false;
bool rightPress = false;
bool forwardPress = false;

// Create a car
Car car;

int main(int argc, char *args[])
{
  // Create window object
  SDL_Window *window = NULL;

  // Initialize video and create the window
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Controllable Car", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  // Create render object
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Initialize SDL Image
  IMG_Init(IMG_INIT_PNG);

  SDL_Texture *texture = loadTexture("car.png", renderer);

  while (running)
  {
    input();
    update();
    draw(renderer, texture);
  }

  // Free up the memory
  IMG_Quit();

  SDL_DestroyWindow(window);
  SDL_Quit();

  // Successful program termination
  return 0;
}

void input()
{
  SDL_Event e;
  if (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
      running = false;
    if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
        case SDLK_UP:
          forwardPress = true;
          break;
        case SDLK_LEFT:
          leftPress = true;
          break;
        case SDLK_RIGHT:
          rightPress = true;
          break;
      }
    }
    if (e.type == SDL_KEYUP)
    {
      switch (e.key.keysym.sym)
      {
        case SDLK_UP:
          forwardPress = false;
          break;
        case SDLK_LEFT:
          leftPress = false;
          break;
        case SDLK_RIGHT:
          rightPress = false;
          break;
      }
    }
  }
}

void update()
{
  if (forwardPress)
    car.move();
  if (leftPress && ! (rightPress))
    car.turn(-1);
  if (rightPress && ! (leftPress))
    car.turn(1);
}

void draw(SDL_Renderer *renderer, SDL_Texture *texture)
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);

  const SDL_Rect carRect = {car.getX(), car.getY(), 64, 64};
  SDL_RenderCopyEx(renderer, texture, NULL, &carRect, car.getDegree(), NULL, SDL_FLIP_HORIZONTAL);

  SDL_RenderPresent(renderer);
}
