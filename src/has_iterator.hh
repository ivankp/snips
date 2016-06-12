#ifndef snip_has_iterator_hh
#define snip_has_iterator_hh

// http://stackoverflow.com/a/3009891/2640636

template <typename T>
struct tovoid { typedef void type; };

template <typename T, typename Enable = void>
struct has_iterator {
  static const bool value = false;
};

template <typename T>
struct has_iterator<T, typename tovoid<typename T::iterator>::type> {
  static const bool value = true;
};

#endif
