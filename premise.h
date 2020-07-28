#include <ostream>
#include <vector>

namespace jesse {
class R {
  virtual std::ostream& OsPrintImpl(std::ostream& os) const {
    return os << "r";
  }

 public:
  virtual ~R() {}
  std::ostream& OsPrint(std::ostream& os) const { return OsPrintImpl(os); }
};

class S : public R {
  std::ostream& OsPrintImpl(std::ostream& os) const { return os << "s"; }
};

struct UnrelatedToR {
  int i_;
  UnrelatedToR(int i) : i_(i) {}
  std::ostream& OsPrint(std::ostream& os) const {
    return os << "UnrelatedToR(" << i_ << ")";
  }
};

struct NotPrintable {};

template <class T>
struct Vec : std::vector<T> {};
}  // namespace jesse
