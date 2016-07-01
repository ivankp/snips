// Developed by Ivan Pogrebnyak

#ifndef snips_catstr_hh
#define snips_catstr_hh

#include <string>
#include <sstream>
#include <utility>

template<typename T>
inline void cat_impl(std::stringstream& ss, T&& x) {
  ss << x;
}

template<typename T, typename... TT>
inline void cat_impl(std::stringstream& ss, T&& x, TT&&... xx) {
  ss << x;
  cat_impl(ss,std::forward<TT>(xx)...);
}

template<typename... TT>
inline std::string cat(TT&&... xx) {
  std::stringstream ss;
  cat_impl(ss,std::forward<TT>(xx)...);
  return ss.str();
}

#endif
