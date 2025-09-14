#include "SpriteComposite.hpp"

void SpriteComposite::addChild(
    const std::string& assetPath,
    bool animated,
    sf::Vector2i frameSize,
    int frameCount,
    float frameRate,
    int columns,
    int rows,
    sf::Vector2f offset
) {
    auto sprite = std::make_shared<SpriteWrapper>(assetPath);

    std::shared_ptr<Animation> anim = nullptr;
    if (animated) {
        std::vector<Frame> frames;
        frames.reserve(frameCount);

        for (int i = 0; i < frameCount; i++) {
            int col = i % columns;
            int row = i / columns;
            sf::IntRect rect(
                { col * frameSize.x, row * frameSize.y },
                { frameSize.x, frameSize.y }
            );
            frames.push_back(Frame{ rect });
        }
        anim = std::make_shared<Animation>(frames, frameRate);
    }

    m_children.push_back({ sprite, anim, offset, true, anim != nullptr, false, false });
}

void SpriteComposite::setVisible(std::size_t index, bool visible) {
    if (index < m_children.size()) m_children[index].visible = visible;
}

void SpriteComposite::setAnimationActive(std::size_t index, bool active) {
    if (index < m_children.size()) {
        auto& child = m_children[index];
        if (child.anim) {
            child.stopAfterCurrentLoop = false;
            child.animActive = active;
            if (!active) child.anim->reset();
        }
    }
}

void SpriteComposite::resetAnimation(std::size_t index) {
    if (index < m_children.size() && m_children[index].anim) m_children[index].anim->reset();
}

bool SpriteComposite::isAnimationGoing() {
    for (auto& child : m_children) {
        if (child.animActive && child.visible) return true;
    }
    return false;
}

void SpriteComposite::update(float dt) {
    for (auto& child : m_children) {
        if (!child.visible) continue;
        if (child.anim) {
            bool finishedLoop = false;
            if (child.animActive) finishedLoop = child.anim->update(dt);
            child.sprite->setTextureRect(child.anim->getRect());

            if (child.stopAfterCurrentLoop && finishedLoop) {
                child.animActive = false;
                child.stopAfterCurrentLoop = false;
                if (child.stopAfterCurrentLoopVisibleToggle) {
                    child.visible = false;
                    child.stopAfterCurrentLoopVisibleToggle = false;
                }
            }
        }
    }
}

void SpriteComposite::stopAnimationAfterLoop(std::size_t index, bool visibleToggle) {
    if (index < m_children.size()) {
        auto& child = m_children[index];
        if (child.anim) {
            child.stopAfterCurrentLoop = true;
            child.stopAfterCurrentLoopVisibleToggle = visibleToggle;
        }
    }
}

void SpriteComposite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto& child : m_children) {
        if (!child.visible) continue;

        sf::Sprite sprite = child.sprite->get();
        sprite.setPosition(child.offset);

        sf::FloatRect bounds = sprite.getLocalBounds();
        if (flipX || flipY) {
            sprite.setOrigin({ flipX ? bounds.size.x : 0.f,
                              flipY ? bounds.size.y : 0.f });
            sprite.setScale({ flipX ? -1.f : 1.f,
                             flipY ? -1.f : 1.f });
        }

        target.draw(sprite, states);
    }
}

size_t SpriteComposite::getChildrenCount() {
    return m_children.size();
}

SpriteComposite::Child SpriteComposite::getChild(int index) {
    return m_children[index];
}

sf::FloatRect SpriteComposite::getGlobalBounds() const {

    sf::Vector2f pos = getPosition();
    sf::Vector2f size;

    const auto& child = m_children[0];

    if (child.anim) {
        auto rect = child.anim->getRect();
        size = { static_cast<float>(rect.size.x), static_cast<float>(rect.size.y) };
    } else {
        auto localBounds = child.sprite->get().getLocalBounds();
        size = { localBounds.size.x, localBounds.size.y };
    }

    return {
        {pos.x, pos.y},
        {size.x, size.y}
    };
}
