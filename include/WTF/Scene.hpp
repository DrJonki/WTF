#pragma once

#include <memory>
#include <map>
#include <SFML/Graphics/View.hpp>
#include <rapidjson/document.h>

namespace sf
{
  class RenderTarget;
}

namespace wtf
{
  class Layer;

  class Scene
  {
  public:

    Scene(Instance& ins);

    virtual ~Scene() = 0;

    Layer& addLayer(const uint32_t weight);

    virtual void update(const float dt);

    virtual void draw(sf::RenderTarget& target);

    void setView(const sf::View& view);

    const sf::View& getView() const;

  private:

    std::multimap<uint32_t, std::unique_ptr<Layer>> m_layers;
    sf::View m_view;
  };
}
