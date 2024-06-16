#include <SDL2/SDL.h>
#include <iostream>
#include "vec3.h"

void renderImage(SDL_Renderer *renderer, int width, int height)
{
    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < width; x++)
        {
            vec3 col(float(x) / float(width), float(y) / float(height), 0.2);
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);
            std::cout << ir << " " << ig << " " << ib << "\n";

            SDL_SetRenderDrawColor(renderer, ir, ig, ib, 255);
            SDL_RenderDrawPoint(renderer, x, height - y);
        }
    }
}

int main()
{
    int width = 800;
    int height = 400;
    std::cout << "P3\n"
              << width << " " << height << "\n255\n";

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr)
    {
        SDL_DestroyWindow(window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Render the image
    renderImage(renderer, width, height);
    SDL_RenderPresent(renderer);

    // Main loop
    bool running = true;
    SDL_Event e;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
            }
        }

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
