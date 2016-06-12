#include <iostream>
#include <vector>

#define test(var) \
  std::cout <<"\033[36m"<< #var <<"\033[0m"<< " = " << var << std::endl;

#include "has_iterator.hh"

int main()
{
  std::cout << std::boolalpha;

  test( has_iterator<int>::value )
  test( has_iterator< std::vector<int> >::value )

  return 0;
}
