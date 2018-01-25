#pragma once

#include <WTF/Macros>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace wtf
{
  class Scene;

  class Instance final
  {
    WTF_NO_COPY;

  public:

    Engine();

    void operator ()();

  private:

    sf::Clock m_clock;
  };
}