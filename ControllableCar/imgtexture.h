#ifndef IMGTEXTURE
#define IMGTEXTURE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

SDL_Texture * loadTexture(std::string path, SDL_Renderer *renderer)
{
  SDL_Texture *newTexture;

  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

  return newTexture;
}

#endif
