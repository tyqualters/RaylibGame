#include "Game.h"

#include "Ball.h"

int main(void) {
    Ball ball({0,0});
    ball.setPosition({100, 100});
    ball.setRadius(50);

    float x = 0;

    Game(800, 600)
    .set_game_loop([&](){
        ball.setPosition({500, x++});
    })
    .start_game();
}