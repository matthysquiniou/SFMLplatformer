#pragma once
#include <memory>
#include "Animation.hpp"
#include "SpriteWrapper.hpp"

class SpriteComposite : public sf::Drawable, public sf::Transformable {
public:
    bool flipX = false;
    bool flipY = false;

    struct Child {
        std::shared_ptr<SpriteWrapper> sprite;
        std::shared_ptr<Animation> anim;
        sf::Vector2f offset{ 0.f,0.f };
        bool visible = true;
        bool animActive = true;
        bool stopAfterCurrentLoop = false;
        bool stopAfterCurrentLoopVisibleToggle = false;
    };

    void addChild(
        const std::string& assetPath,
        bool animated,
        sf::Vector2i frameSize = { 0,0 },
        int frameCount = 1,
        float frameRate = 0.1f,
        int columns = 1,
        int rows = 1,
        sf::Vector2f offset = { 0.f, 0.f }
    );

    void setVisible(std::size_t index, bool visible);
    void setAnimationActive(std::size_t index, bool active);
    bool isAnimationGoing();
    void resetAnimation(std::size_t index);
    void update(float dt);
    void stopAnimationAfterLoop(std::size_t index, bool visibleToggle = false);
    sf::FloatRect getGlobalBounds() const;
    size_t getChildrenCount();
    Child getChild(int index);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<Child> m_children;
};
