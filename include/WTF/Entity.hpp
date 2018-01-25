#pragma once

#include <string>

namespace sf
{
  class RenderTarget;
}

namespace wtf
{
  class Entity
  {
    friend class Layer;

  public:

    Entity(const std::string& name);

    virtual ~Entity() = 0;

    void erase();

    bool isErased() const;

    void setActive(const bool active);

    bool isActive() const;

    const std::string& getName() const;

  private:

    void baseUpdate(const float dt);

    void baseDraw(sf::RenderTarget& target);

    virtual void update(const float dt);

    virtual void draw(sf::RenderTarget& target);

  private:

    const std::string m_name;
    bool m_active;
    bool m_deleted;
  };
}
