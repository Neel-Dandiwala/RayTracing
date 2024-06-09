#include <SDL2/SDL.h>
#include <iostream>

int main() {
    // Image dimensions
    int image_width = 800;
    int image_height = 400;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Ray Tracer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, image_width, image_height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Render the image
    for (int y = 0; y < image_height; y++) {
        for (int x = 0; x < image_width; x++) {
            auto r = double(x) / image_width;
            auto g = double(y) / image_height;
            auto b = 0.2;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            SDL_SetRenderDrawColor(renderer, ir, ig, ib, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    // Present the renderer
    SDL_RenderPresent(renderer);

    // Main loop
    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear screen with a color (optional)
        SDL_SetRenderDrawColor(renderer, 200, 100, 0, 255); // Black color
        SDL_RenderClear(renderer);

        // Draw the image again
        for (int y = 0; y < image_height; y++) {
            for (int x = 0; x < image_width; x++) {
                auto r = double(x) / image_width;
                auto g = double(y) / image_height;
                auto b = 0.2;

                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                SDL_SetRenderDrawColor(renderer, ir, ig, ib, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
