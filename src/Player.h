#pragma once

#include <raylib.h>

void ClampV2(Vector2& v2, Vector2 v2min, Vector2 v2max) {
    v2.x = (v2.x < v2min.x) ? v2min.x : (v2.x > v2max.x) ? v2max.x : v2.x;
    v2.y = (v2.y < v2min.y) ? v2min.y : (v2.y > v2max.y) ? v2max.y : v2.y;
}

class Player {
public:
    Player(int x, int y, int w) {
        this->x = (float)x;
        this->y = (float)y;
        this->w = (float)w;
        this->h = (float)w;
        texture = LoadTexture("assets/bugs.png");
    }

    ~Player() {
        UnloadTexture(texture);
    }

    Vector2 getPosition() const {
        return Vector2{x, y};
    }

    float getRadius() {
        return 0.f;
    }

    void setPosition(Vector2 newPos) {
        x = newPos.x;
        y = newPos.y;
    }

    void draw() {
        DrawRectangle(x, y, w, h, RED);
        // DrawTextureEx(texture, {x, y}, 0.f, 1.f, WHITE);
    }

    void controller(int winWidth, int winHeight, float speed) {
        if(IsKeyDown(KEY_W)) {
            auto oldPos = getPosition();
            auto newPos = Vector2{oldPos.x, oldPos.y - speed};
            float radius = (float)getRadius();
            ClampV2(newPos, {radius, radius}, {winWidth - radius, winHeight - radius});
            setPosition(newPos);
        }
        if(IsKeyDown(KEY_A)) {
            auto oldPos = getPosition();
            auto newPos = Vector2{oldPos.x - speed, oldPos.y};
            float radius = (float)getRadius();
            ClampV2(newPos, {radius, radius}, {winWidth - radius, winHeight - radius});
            setPosition(newPos);
        }
        if(IsKeyDown(KEY_S)) {
            auto oldPos = getPosition();
            auto newPos = Vector2{oldPos.x, oldPos.y + speed};
            float radius = (float)getRadius();
            ClampV2(newPos, {radius, radius}, {winWidth - radius, winHeight - radius});
            setPosition(newPos);
        }
        if(IsKeyDown(KEY_D)) {
            auto oldPos = getPosition();
            auto newPos = Vector2{oldPos.x + speed, oldPos.y};
            float radius = (float)getRadius();
            ClampV2(newPos, {radius, radius}, {winWidth - radius, winHeight - radius});
            setPosition(newPos);
        }
    }

private:
    float x, y, w, h;
    Texture2D texture;
};