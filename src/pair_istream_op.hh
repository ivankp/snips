// Developed by Ivan Pogrebnyak, MSU

#ifndef PAIR_ISTREAM_OPERATOR_HH
#define PAIR_ISTREAM_OPERATOR_HH

#include <utility>
#include <istream>
#include <sstream>

namespace std {
  template <typename T1, typename T2>
  istream& operator>>(istream& in, pair<T1,T2>& p) {
    stringstream s1, s2;
    in.get(*s1.rdbuf(),':');
    s1 >> p.first;
    in.ignore(); // skip delim char
    in.get(*s2.rdbuf(),(char)EOF);
    s2 >> p.second;
    return in;
  }
}

#endif
