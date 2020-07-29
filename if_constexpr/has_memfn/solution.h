namespace jesse {
template <class, class = void>
constexpr bool CanOsPrint_v = false;

template <class T>
constexpr bool CanOsPrint_v<T,
                            decltype(void(std::declval<const T>().OsPrint(
                                std::declval<std::ostream&>())))> = true;

template <class T>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  if constexpr (CanOsPrint_v<T>)
    for (const auto& t : vec)
      t.OsPrint(os);
  else
    os << "(nothing)";
  return os;
}
}  // namespace jesse
