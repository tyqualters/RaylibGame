#include "Common.h"
#include "Game.h"
#include "Player.h"

#include <iostream>

// NEW PRIORITY
//  #1 COLLIDER

// Summary of plans:
//  Collider class will encompass all physical objects in the game.
//  Movement will be applied by adding directional acceleration not by directly changing velocity.
//  See Collider.h for more information.

int main(void) {
    constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
    
    // Static initializations
    Player mainPlayer((WINDOW_WIDTH / 2), WINDOW_HEIGHT - 100, 60, "assets/bugs.png");

    Game(WINDOW_WIDTH, WINDOW_HEIGHT)
    // Load GL-dependant parts of game objects
    .add_loadable(mainPlayer)
    // Game loop
    .set_game_loop([&](){
        
    })
    // Run game loop
    .start_game();
}