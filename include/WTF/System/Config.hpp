#pragma once

namespace wtf
{
  class Config
  {
  private:

    static void ensureInit();

  public:

    template<typename T>
    static T get(const std::string& key);
  };
}
