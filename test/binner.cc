#include <iostream>
#include <vector>

#include "binner.hh"

#define test(var) \
  std::cout <<"\033[36m"<< #var <<"\033[0m"<< " = " << var << std::endl;

using namespace std;

int main()
{
  binner<double> histD(5,0,5);

  histD.fill(0.5);
  histD.fill(1);
  histD(3,5);
  histD(4.1,3);
  histD(3.9);
  histD(5,9);
  histD(-1,7);

  for (unsigned i=0; i<histD.bins().size(); ++i)
    cout << "bin "<< i << " ["
         << histD.ledge(i) << ',' << histD.redge(i)
         << "): " << histD[i] << endl;

  cout << endl;
  // **********************************

  binner<binner<double>> bb(3,0,3);
  for (auto& bin : bb.bins()) bin = {1,2};
  bb.bins().back() = {1,3,6,8};

  for (unsigned i=0; i<bb.bins().size(); ++i)
    for (unsigned j=0; j<bb[i].bins().size(); ++j)
      cout << "bin "<< i<<','<<j << " ["
           << bb.ledge(i) << ',' << bb.redge(i) << ")["
           << bb[i].ledge(j) << ',' << bb[i].redge(j)
           << "): " << bb[i][j] << endl;

  return 0;
}
