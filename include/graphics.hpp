#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SDL.h"

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 144
#define SCREEN_SCALE 10

class Graphics {
    public:
        Graphics();
        ~Graphics();
        bool Init();
        void Clear();
        void Draw();
        void Update();
        void SetPixel(int x, int y, uint32_t value);
        bool GetPixel(int x, int y);
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        bool running;
        uint32_t pixels[SCREEN_WIDTH][SCREEN_HEIGHT];
};


#endif // GRAPHICS_HPP