#include <iostream>
#include "premise.h"
#include "solution.h"

namespace jesse {
extern "C" int main() {
  typedef Vec<int> IntVec;
  typedef Vec<R> RVec;
  typedef Vec<S> SVec;
  typedef Vec<UnrelatedToR> URVec;
  typedef Vec<NotPrintable> NPVec;

  IntVec iv;
  iv.resize(3);

  SVec sv;
  sv.resize(3);

  RVec rv;
  rv.resize(3);

  URVec urv;
  urv.push_back(1);
  urv.push_back(2);
  urv.push_back(3);

  NPVec npv;

  std::cout << "iv:\t" << iv << "\n";
  std::cout << "sv:\t" << sv << "\n";
  std::cout << "rv:\t" << rv << "\n";
  std::cout << "urv\t" << urv << "\n";
  std::cout << "npv\t" << npv << "\n";
  return 0;
}
}  // namespace jesse
