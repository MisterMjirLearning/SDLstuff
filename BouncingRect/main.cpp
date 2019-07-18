// Get all the SDL2 Good Stuff
#include <SDL2/SDL.h>

// Function prototypes
void input();
void update();
void draw(SDL_Renderer *);

// Globals
bool running = true; // Game Running
const int WIDTH = 1200; // Screen Width
const int HEIGHT = 800; // Screen Height

// Stuff for the rectangle
/* NOTE
 * Ideally this should be a class
 * which has a SDL Rect and the
 * dx and dy in it, but since this
 * is a simple program, I am cheating
 */
SDL_Rect rect = {0, 0, 64, 64};
int dx = 1, dy = 1; // How it will change distance

int main(int argc, char *args[])
{
  // Create window object
  SDL_Window *window = NULL;

  // Initialize video and create the window
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Bouncing Rect", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

  // Create the renderer
  SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Game loop
  /* NOTE
   * This is a terrible loop, don't use it. There are at least three good guides
   * on how to make a good game loop, you can look at those (on google).
   */
  while (running)
  {
    input();
    update();
    draw(render);
  }

  // Free up the memory
  SDL_DestroyWindow(window);
  SDL_Quit();

  // Successful program termination
  return 0;
}

// Get inputs
void input()
{
  // Only checks if user has closed the window, then closes the window
  SDL_Event e;
  if (SDL_PollEvent(&e))
    if (e.type == SDL_QUIT)
      running = false;
}

// Handle movements
void update()
{
  // Move the square
  rect.x += dx;
  rect.y += dy;

  // Check collisions
  if (rect.y > HEIGHT) // Bottom
    dy = -1;
  if (rect.y < 0) // Top
    dy = 1;
  if (rect.x + rect.w > WIDTH) // Right
    dx = -1;
  if (rect.x < 0) // Left
    dx = 1;
}

// Rendering stuff
void draw(SDL_Renderer *render)
{
  // Clear the window and make it white
  SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
  SDL_RenderClear(render);

  // Draw the square
  /* NOTE
   * This should be a method in the square class
   * that this function calls
   */
  SDL_SetRenderDrawColor(render, 20, 180, 180, 255);
  SDL_RenderFillRect(render, &rect);

  // Update the window
  SDL_RenderPresent(render);
}
