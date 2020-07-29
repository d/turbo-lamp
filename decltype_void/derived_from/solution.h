namespace jesse {
template <class T>
constexpr bool DerivedFromR_v = std::is_base_of<R, T>::value;

template <class T, std::enable_if_t<!DerivedFromR_v<T>, bool> = true>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  return os << "(nothing)";
}

template <class T, std::enable_if_t<DerivedFromR_v<T>, bool> = true>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  for (auto& t : vec)
    t.OsPrint(os);
  return os;
}
}  // namespace jesse
