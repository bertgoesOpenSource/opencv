#include <stdio.h>
#include <vector>
#define ulong unsigned long

using namespace std;

class inversionImpl{
public:
  inversionImpl(){};
  ulong sortAndCount(vector<int>&);
  vector<int> merge(vector<int>, vector<int>);
  void split(vector<int>, vector<int>&, vector<int>&);
  ulong sortTrivialAndCount(vector<int>&);
  ulong splitCount(vector<int>&, vector<int>, vector<int>);
  void print(vector<int>);
  void print(ulong);
  
};
