#pragma once

#include <raylib.h>

void ClampV2(Vector2& v2, Vector2 v2min, Vector2 v2max) {
    v2.x = (v2.x < v2min.x) ? v2min.x : (v2.x > v2max.x) ? v2max.x : v2.x;
    v2.y = (v2.y < v2min.y) ? v2min.y : (v2.y > v2max.y) ? v2max.y : v2.y;
}

// WithinBounds is for basic collision detection (rectangles)
// TODO:
// For more complex collision detection, we will need to utilize vectors of vertices and indices
// Touching =/= collided, so check if momentum/velocity pushes into object
bool WithinBounds(Vector4 v4obj1, Vector4 v4obj2) {
    // Within x range
    if (v4obj2.x >= v4obj1.x && v4obj2.z <= v4obj1.z)
        // Within y range
        if (v4obj2.y <= v4obj1.y && v4obj2.w >= v4obj1.w)
            // True if both conditions met
            return true;
    return false;
}

// Note: Might be optimized to be inline, might not.
int RoundFloat(float x) {
    return (x - static_cast<int>(x)) >= 0.5f ? static_cast<int>(x) + 1 : static_cast<int>(x);
}

class Player {
public:
    Player(float x0, float y0, float w0, const char* playerTexture) {
        x = x0;
        y = y0;
        h = w = w0;

        //Image image = LoadImage(playerTexture);
        //ImageResize(&image, w, h);
        //texture = LoadTextureFromImage(image);
        //UnloadImage(image);
    }

    ~Player() {
        //UnloadTexture(texture);
    }

    Vector2 getPosition() const {
        return Vector2{x, y};
    }

    // Note: Not really a radius for a square but w/e
    float getRadius() {
        return w / 2.f;
    }

    void setPosition(Vector2 newPos) {
        x = newPos.x;
        y = newPos.y;
    }

    void draw() {
        float radius = getRadius();
        // DrawCircle(x, y, radius, RED);
        // Rectangle and Circle do not have the same origin points
        // Rectangle origin point is Top-Left, Circle origin point is Center point
        // By subtracting getRadius() we are essentially forcing the origin point to the Center point
        
        // Rectangle prefers ints over floats
        DrawRectangle(
            RoundFloat(x - radius),
            RoundFloat(y - radius),
            RoundFloat(w),
            RoundFloat(h), 
            RED
        );
        //DrawTexture(texture, RoundFloat(x), RoundFloat(y), Color{ 0, 0, 0, 0 });
    }

    void controller(int winWidth, int winHeight, float speed) {
        // Simplify with offsets
        Vector2 pos = getPosition();
        float radius = getRadius();

        if (IsKeyDown(KEY_W)) pos.y -= speed;
        if (IsKeyDown(KEY_A)) pos.x -= speed;
        if (IsKeyDown(KEY_S)) pos.y += speed;
        if (IsKeyDown(KEY_D)) pos.x += speed;

        ClampV2(pos, { radius, radius }, { winWidth - radius, winHeight - radius });
        setPosition(pos);
    }

private:
    float x = 0.f, y = 0.f, w = 0.f, h = 0.f;
    Texture2D texture{};
};