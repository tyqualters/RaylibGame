#pragma once

#include <cstdint>
#include <random>
#include <ctime>
#include <unordered_map>

#include <raylib.h>

class IRenderable {
public:
    IRenderable() {
        this->m_uuid = IRenderable::GenerateUUID();
        IRenderable::RenderSet[this->m_uuid] = this;
    }

    ~IRenderable() {
        IRenderable::RenderSet.erase(this->m_uuid);
    }

    virtual void draw() = 0;

    static std::unordered_map<uint32_t, IRenderable*> RenderSet;

    static uint32_t GenerateUUID() {
        static std::random_device randDev;
        std::mt19937 mt(randDev());
        std::uniform_int_distribution<uint32_t> dist;
        dist.param(std::uniform_int_distribution<uint32_t>::param_type(0, std::numeric_limits<uint32_t>::max()));
        uint32_t result = dist(mt);
        if(IRenderable::RenderSet.contains(result)) return IRenderable::GenerateUUID();
        else return result;
    }

protected:
    uint32_t m_uuid;
};

std::unordered_map<uint32_t, IRenderable*> IRenderable::RenderSet{};