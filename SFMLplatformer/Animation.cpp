#include "Animation.hpp"

Animation::Animation(std::vector<Frame> frames, float delaySec)
    : m_frames(std::move(frames)), m_delay(delaySec) {
}

bool Animation::update(float dt) {
    if (m_frames.empty()) return false;
    m_elapsed += dt;
    bool finished = false;
    if (m_elapsed >= m_delay) {
        m_elapsed = 0.f;
        m_index++;
        if (m_index >= m_frames.size()) {
            m_index = 0;
            finished = true;
        }
    }
    return finished;
}

void Animation::reset() {
    m_index = 0;
    m_elapsed = 0.f;
}

const sf::IntRect& Animation::getRect() const {
    return m_frames[m_index].rect;
}

const sf::IntRect& Animation::getFirstRect() const {
    return m_frames[0].rect;
}