#pragma once

#include <functional>

#include <raylib.h>

#include "Drawable.h"

typedef std::function<void(void)> GAME_LOOP_FN;

class Game {
public:
    Game(int w, int h) {
        InitWindow(w, h, "Raylib game");
        SetTargetFPS(60);
    }

    ~Game() {
        CloseWindow();
    }

    Game& set_game_loop(GAME_LOOP_FN fn) {
        this->m_game_loop = fn;
        return *this;
    }

    void start_game() {
        while (!WindowShouldClose()) {
            // Frame specific variables
            this->deltaTime = GetFrameTime();
            this->mousePos = GetMousePosition();
            // Frame specific variables
            
            // Game Loop
            this->m_game_loop();
            // Game Loop

            // Drawing
            BeginDrawing();
            ClearBackground(WHITE);
            for(const auto& key_value_pair : IRenderable::RenderSet) {
                key_value_pair.second->draw();
            }
            EndDrawing();
            // Drawing
	    }
    }

private:
    float deltaTime;
    Vector2 mousePos;
    std::function<void(void)> m_game_loop;
};