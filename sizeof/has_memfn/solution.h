#include <algorithm>
namespace jesse {
// poor man's void_t<decltype(...)>. Use it like val_t<sizeof(expression)>::type
// where ill-formed expression can give you SFINAE
template <size_t>
struct val_t {
  typedef void type;
};

template <class, class = void>
struct CanOsPrint {};

template <class T>
struct CanOsPrint<T,
                  typename val_t<sizeof(
                      static_cast<std::ostream& (T::*)(std::ostream&) const>(
                          &T::OsPrint))>::type> {
  typedef void type;
};

template <class T, class = void>
struct OsPrintTrait {
  static std::ostream& OsPrint(std::ostream& os, Vec<T>&) {
    return os << "(nothing)";
  }
};

template <class T>
struct OsPrintTrait<T, typename CanOsPrint<T>::type> {
  static std::ostream& OsPrint(std::ostream& os, Vec<T>& vec) {
    std::for_each(vec.begin(), vec.end(),
                  std::bind2nd(std::mem_fun_ref(&T::OsPrint), os));
    return os;
  }
};

template <class T>
std::ostream& operator<<(std::ostream& os, Vec<T>& vec) {
  return OsPrintTrait<T>::OsPrint(os, vec);
}

}  // namespace jesse
