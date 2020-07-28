namespace jesse {
template <class T>
concept OsPrintable = requires(T t, std::ostream& o) {
  t.OsPrint(o);
};

template <OsPrintable T>
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
