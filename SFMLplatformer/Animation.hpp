#pragma once
#include <SFML/Graphics.hpp>

struct Frame {
    sf::IntRect rect;
};

class Animation {
public:
    Animation(std::vector<Frame> frames, float delaySec);

    bool update(float dt);
    void reset();

    const sf::IntRect& getRect() const;
    const sf::IntRect& getFirstRect() const;

private:
    std::vector<Frame> m_frames;
    float m_delay;
    float m_elapsed = 0.f;
    std::size_t m_index = 0;
};