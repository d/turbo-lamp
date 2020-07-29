namespace jesse {
template <class, class = void>
constexpr bool CanOsPrint_v = false;

template <class T>
constexpr bool CanOsPrint_v<T,
                            decltype(void(std::declval<const T>().OsPrint(
                                std::declval<std::ostream&>())))> = true;

template <class T, std::enable_if_t<CanOsPrint_v<T>, bool> = true>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  for (const auto& t : vec)
    t.OsPrint(os);
  return os;
}

template <class T, std::enable_if_t<!CanOsPrint_v<T>, bool> = true>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  return os << "(nothing)";
}
}  // namespace jesse
