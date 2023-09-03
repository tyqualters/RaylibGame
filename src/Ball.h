#pragma once

#include "Drawable.h"

class Ball : public IRenderable {
public:
    Ball(Vector2 position) {
        this->m_position = position;
    }

    void draw() override {
        DrawCircle(this->m_position.x, this->m_position.y, this->m_radius, RED);
    }

    void setRadius(int r) {
        this->m_radius = r;
    }

    int getRadius() const {
        return this->m_radius;
    }

    void setPosition(Vector2 position) {
        this->m_position = position;
    }

    Vector2 getPosition() const {
        return this->m_position;
    }

private:
    Vector2 m_position;
    int m_radius;
};