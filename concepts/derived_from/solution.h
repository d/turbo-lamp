namespace jesse {
template <class T>
concept DerivedFromR = std::is_base_of_v<R, T>;

template <DerivedFromR T>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  for (const auto& t : vec)
    t.OsPrint(os);
  return os;
}

template <class T>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  return os << "(nothing)";
}
}  // namespace jesse
