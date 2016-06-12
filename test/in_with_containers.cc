#include <iostream>
#include <vector>

#define test(var) \
  std::cout <<"\033[36m"<< #var <<"\033[0m"<< " = " << var << std::endl;

using namespace std;

#include "in_with_containers.hh"

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

  test( in(3,initializer_list<int>{1,2,6},vector<int>{1,2,3},7,8,9) )

  return 0;
}
