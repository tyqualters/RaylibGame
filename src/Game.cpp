#include "Game.h"

#include "Ball.h"

#include <iostream>
#include <vector>

void ClampV2(Vector2& v2, Vector2 v2min, Vector2 v2max) {
    v2.x = (v2.x < v2min.x) ? v2min.x : (v2.x > v2max.x) ? v2max.x : v2.x;
    v2.y = (v2.y < v2min.y) ? v2min.y : (v2.y > v2max.y) ? v2max.y : v2.y;
}

// TODO: Fix this function
bool WithinBounds(Vector4 v4o1, Vector4 v4o2) {
    // Check if x is within bounds
    if(v4o1.x >= v4o2.x && v4o1.z <= v4o2.z)
        // x is within bounds
        // Check if y is within bounds
        if(v4o1.y >= v4o2.y && v4o1.w <= v4o1.w)
            // y is within bounds
            return true;
    return false;
}

constexpr float g_GRAVITY = 1.5f;


struct Tile {
    Vector2 startingPoint; // Top Left point
    int w, h;
};

template<class T>
void ApplyGravity(T&) = delete;

template<>
void ApplyGravity(Tile& object) {
    object.startingPoint.y += g_GRAVITY;
}

// void TileGen(std::vector<Tile>& tiles, float maxHeight) {
//     if(tiles.size() < 5UL) {
//         tiles.push_back({{0,0}, 100, 25});
//     }
//     for(auto& tile : tiles) {
        
//     }
// }

int main(void) {
    constexpr int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;

    constexpr float BALL_SPEED = 6.f;

    Ball ball({0,0});
    ball.setRadius(50);
    // Center the ball
    ball.setPosition({(float)WINDOW_WIDTH / 2, (float)WINDOW_HEIGHT / 2 - ball.getRadius() / 2});

    std::vector<Tile> tiles{};
    tiles.push_back({{300, 0}, 100, 25});

    Game(WINDOW_WIDTH, WINDOW_HEIGHT)
    .set_game_loop([&](){
        if(IsKeyDown(KEY_W)) {
            auto oldPos = ball.getPosition();
            auto newPos = Vector2{oldPos.x, oldPos.y - BALL_SPEED};
            float radius = (float)ball.getRadius();
            ClampV2(newPos, {radius, radius}, {WINDOW_WIDTH - radius, WINDOW_HEIGHT - radius});
            ball.setPosition(newPos);
        }
        if(IsKeyDown(KEY_A)) {
            auto oldPos = ball.getPosition();
            auto newPos = Vector2{oldPos.x - BALL_SPEED, oldPos.y};
            float radius = (float)ball.getRadius();
            ClampV2(newPos, {radius, radius}, {WINDOW_WIDTH - radius, WINDOW_HEIGHT - radius});
            ball.setPosition(newPos);
        }
        if(IsKeyDown(KEY_S)) {
            auto oldPos = ball.getPosition();
            auto newPos = Vector2{oldPos.x, oldPos.y + BALL_SPEED};
            float radius = (float)ball.getRadius();
            ClampV2(newPos, {radius, radius}, {WINDOW_WIDTH - radius, WINDOW_HEIGHT - radius});
            ball.setPosition(newPos);
        }
        if(IsKeyDown(KEY_D)) {
            auto oldPos = ball.getPosition();
            auto newPos = Vector2{oldPos.x + BALL_SPEED, oldPos.y};
            float radius = (float)ball.getRadius();
            ClampV2(newPos, {radius, radius}, {WINDOW_WIDTH - radius, WINDOW_HEIGHT - radius});
            ball.setPosition(newPos);
        }


        auto ballPos = ball.getPosition();
        auto ballRadius = ball.getRadius();
        for(auto& tile : tiles) {
            auto& point = tile.startingPoint;
            ApplyGravity(tile);
            DrawRectangle(point.x, point.y, tile.w, tile.h, RED);
            // TODO: Fix collision (see WithinBounds fn)
            // if(WithinBounds({ballPos.x, ballPos.y, ballPos.x + ballRadius * 2, ballPos.y + ballRadius * 2}, {point.x, point.y, point.x + tile.w, point.y + tile.h})) {
            //     std::cout << "Ball collided." << std::endl;
            //     std::cin.get();
            //     std::exit(0);
            // }
        }
    })
    .start_game();
}