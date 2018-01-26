#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <WTF/Entity.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace sf
{
  class RenderTarget;
}

namespace wtf
{
  class Layer final : public sf::Transformable
  {
  public:

    Layer();

    ~Layer();

    template<typename T, typename ... Args>
    T& insert(const std::string& name, Args&&... args);

    void update(const float dt);

    void draw(sf::RenderTarget& target);

    void setView(const sf::View& view);

    const sf::View& getView() const;

    void setActive(const bool active);

    bool isActive() const;

  private:

    std::unordered_multimap<std::string, std::unique_ptr<Entity>> m_entities;
    sf::View m_view;
    bool m_active;
  };

  #include <WTF/Layer.inl>
}

