// Developed by Ivan Pogrebnyak

#ifndef make_unique_hh
#define make_unique_hh

#include <memory>

template <typename T, typename... Args>
std::unique_ptr<T> make_unique( Args&& ...args ) {
  return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

#endif
