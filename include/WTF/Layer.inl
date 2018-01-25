template<typename T, typename ... Args>
T& Layer::insert(const std::string& name, Args&&... args) {
  static_assert(std::is_base_of<Entity, T>::value, "Not an entity");

  auto uniq = std::make_unique<T>(name, args...);
  auto& ref = *uniq;
  m_entities.emplace(name, std::move(uniq));

  return ref;
}
