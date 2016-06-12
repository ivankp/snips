#ifndef snip_in_with_containers_hh
#define snip_in_with_containers_hh

#include <type_traits>

#include "has_iterator.hh"

template <typename T1, typename T2>
bool in(T1 x, const initializer_list<T2>& list) {
  for (const auto& a : list) if (x==a) return true;
  return false;
}

template <typename T1, typename T2>
inline typename std::enable_if<!has_iterator<T2>::value,bool>::type
in(const T1& x, const T2& a) noexcept(noexcept(x==a)) { return x==a; }

template <typename T1, typename T2>
typename std::enable_if<has_iterator<T2>::value,bool>::type
in(const T1& x, const T2& list) {
  for (const auto& a : list) if (x==a) return true;
  return false;
}

template <typename T1, typename T2, typename... TT>
inline bool in(const T1& x, const T2& a, const TT&... bb) {
  return in(x,a) || in(x,bb...);
}

#endif
