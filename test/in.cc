#include <iostream>

#define test(var) \
  std::cout <<"\033[36m"<< #var <<"\033[0m"<< " = " << var << std::endl;

using namespace std;

#include <vector>
template <typename T1, typename T2>
bool in(T1 x, const vector<T2>& list) {
  cout << "vector" << endl;
  for (auto a : list) if (x==a) return true;
  return false;
}

template <typename T1, typename T2>
bool in(T1 x, const initializer_list<T2>& list) {
  cout << "initializer_list" << endl;
  for (auto a : list) if (x==a) return true;
  return false;
}

#include "in.hh"
// doesn't work if included before overloading functions

int main()
{
  cout << boolalpha;

  test( in(3,1,2,3) )
  test( in(3,1,2,6) )

  test( in(3,1,2,3.0) )

  test( in(3,{1,2,3}) )
  test( in(3,{1,2,6}) )

  test( in(3,vector<int>{1,2,6}) )

  test( in(3,vector<int>{1,2,6},3) )

  return 0;
}
