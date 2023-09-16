#include "Game.h"

#include "Player.h"

#include <iostream>
#include <vector>

constexpr float g_GRAVITY = 1.5f;

template<class T>
void ApplyGravity(T&) = delete;

// template<>
// void ApplyGravity(Tile& object) {
//     object.startingPoint.y += g_GRAVITY;
// }

int main(void) {
    constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;

    Player mainPlayer(50, 50, 60, "assets/bugs.png");
    
    Game(WINDOW_WIDTH, WINDOW_HEIGHT)
    .set_game_loop([&](){
        mainPlayer.draw();
        mainPlayer.controller(WINDOW_WIDTH, WINDOW_HEIGHT, 8.f);
    })
    .start_game();
}