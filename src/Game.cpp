#include "Game.h"

#include "Player.h"

#include "Collider.h"

#include <iostream>
#include <vector>

constexpr float g_GRAVITY = 1.5f;

template<class T>
void ApplyGravity(T&) = delete;

// template<>
// void ApplyGravity(Tile& object) {
//     object.startingPoint.y += g_GRAVITY;
// }




class CollidableBox : public Collider {
public:
    CollidableBox(int x, int y, int w, int h) : Collider(Vector2{ (float)x, (float)y }, Vector2{ (float)w, (float)h }) {

    }

    void draw() {
        DrawRectangle(point.x, point.y, dimensions.x, dimensions.y, RED);
    }
};




int main(void) {
    constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
    
    //Player mainPlayer(50, 50, 60, "assets/bugs.png");

    CollidableBox box1(50, 50, 50, 50);
    CollidableBox box2(50, 400, 50, 50);

    auto applyBoxGravity = [](CollidableBox& b1) {
        b1.add_force(Vector2{ 0, 1 }, 1.0f);
    };

    Game(WINDOW_WIDTH, WINDOW_HEIGHT)
    // Load GL-dependant parts of game objects
    //.add_loadable(mainPlayer)
    // Game loop
    .set_game_loop([&](){
        box1.draw();
        box2.draw();
        applyBoxGravity(box1);
        box1.apply_movement(box2);
        box1.negate_force(1.0f);
        box2.negate_force(1.0f);
        //mainPlayer.draw();
        //mainPlayer.controller(WINDOW_WIDTH, WINDOW_HEIGHT, 8.f);
    })
    .start_game();
}