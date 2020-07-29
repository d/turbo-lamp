namespace jesse {
template <class T>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  if constexpr (std::is_base_of_v<R, T>)
    for (const auto& t : vec)
      t.OsPrint(os);
  else
    os << "(nothing)";
  return os;
}
}  // namespace jesse
