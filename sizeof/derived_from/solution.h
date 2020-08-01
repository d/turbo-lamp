#include <algorithm>
#include <functional>
namespace jesse {
// poor man's void_t<decltype(...)>. Use it like val_t<sizeof(expression)>::type
// where ill-formed expression can give you SFINAE
template <size_t>
struct val_t {
  typedef void type;
};

namespace details {
template <class T>
bool yolo(const volatile T*);
}

template <class, class = void>
struct DerivedFromR {};

template <class T>
struct DerivedFromR<T, typename val_t<sizeof(details::yolo<R>((T*)0))>::type> {
  typedef void type;
};

template <class T, class = void>
struct OsPrintTrait {
  static std::ostream& OsPrint(std::ostream& os, Vec<T>&) {
    return os << "(nothing)";
  }
};

template <class T>
struct OsPrintTrait<T, typename DerivedFromR<T>::type> {
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
