#pragma once

#include "Common.h"
#include "Drawable.h"
#include "GameLoadable.h"

#include <functional>

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

    Game& add_loadable(IGameLoadable& loadable) {
        loadable.load();
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
    float deltaTime = 0.f;
    Vector2 mousePos{ 0.f, 0.f };
    std::function<void(void)> m_game_loop;
};