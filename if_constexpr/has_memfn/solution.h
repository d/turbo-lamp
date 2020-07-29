namespace jesse {
template <class T, class = void>
struct CanOsPrint : std::false_type {};
template <class T>
struct CanOsPrint<T,
                  decltype(void(std::declval<const T>().OsPrint(
                      std::declval<std::ostream&>())))> : std::true_type {};

template <class T>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  if constexpr (CanOsPrint<T>::value)
    for (const auto& t : vec)
      t.OsPrint(os);
  else
    os << "(nothing)";
  return os;
}
}  // namespace jesse
