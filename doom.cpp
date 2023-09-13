#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

// Define screen constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Define player constants
const int PLAYER_WIDTH = 32;
const int PLAYER_HEIGHT = 32;
const int PLAYER_SPEED = 5;

// Define bullet constants
const int BULLET_WIDTH = 8;
const int BULLET_HEIGHT = 8;
const int BULLET_SPEED = 10;

// Define enemy constants
const int ENEMY_WIDTH = 32;
const int ENEMY_HEIGHT = 32;
const int ENEMY_SPEED = 3;

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create the game window
    SDL_Window* window = SDL_CreateWindow("2D Doom", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create the game renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Load game resources
    SDL_Texture* player_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("player.bmp"));
    SDL_Texture* bullet_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("bullet.bmp"));
    SDL_Texture* enemy_texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("enemy.bmp"));

    // Create game objects
    SDL_Rect player = {SCREEN_WIDTH/2 - PLAYER_WIDTH/2, SCREEN_HEIGHT/2 - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT};
    SDL_Rect bullet = {0, 0, BULLET_WIDTH, BULLET_HEIGHT};
    SDL_Rect enemy = {SCREEN_WIDTH/4 - ENEMY_WIDTH/2, SCREEN_HEIGHT/4 - ENEMY_HEIGHT/2, ENEMY_WIDTH, ENEMY_HEIGHT};
    int enemy_direction = 1;

    // Set up the game loop
    bool running = true;
    while (running) {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    bullet.x = player.x + PLAYER_WIDTH/2 - BULLET_WIDTH/2;
                    bullet.y = player.y + PLAYER_HEIGHT/2 - BULLET_HEIGHT/2;
                }
            }
        }

        // Move the player
        const Uint8* keyboard_state = SDL_GetKeyboardState(NULL);
        if (keyboard_state[SDL_SCANCODE_W]) {
            player.y -= PLAYER_SPEED;
        }
        if (keyboard_state[SDL_SCANCODE_S]) {
            player.y += PLAYER_SPEED;
        }
        if (keyboard_state[SDL_SCANCODE_A]) {
            player.x -= PLAYER_SPEED;
        }
        if (keyboard_state[SDL_SCANCODE_D]) {
            player.x += PLAYER_SPEED;
        }

        // Move the bullet
        if (bullet.x > 0) {
            bullet.x += BULLET_SPEED;
        }

        // Move the enemy
        enemy.x += ENEMY_SPEED * enemy_direction;
        if (enemy.x < 0 || enemy.x > SCREEN_WIDTH - ENEMY_WIDTH) {
            enemy_direction *= -1;
        }

        // Check for collisions
        if (bullet.x > 0 && bullet.x + BULLET_WIDTH > enemy.x && bullet.x < enemy.x + ENEMY_WIDTH && bullet.y + BULLET_HEIGHT > enemy.y && bullet.y < enemy.y + ENEMY_HEIGHT) {
            enemy.x = SCREEN_WIDTH/4 - ENEMY_WIDTH/2;
            enemy.y = SCREEN_HEIGHT/4 - ENEMY_HEIGHT/2;
            bullet.x = 0;
        }

        // Render the game
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, player_texture, NULL, &player);
        SDL_RenderCopy(renderer, bullet_texture, NULL, &bullet);
        SDL_RenderCopy(renderer, enemy_texture, NULL, &enemy);
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyTexture(player_texture);
    SDL_DestroyTexture(bullet_texture);
    SDL_DestroyTexture(enemy_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}