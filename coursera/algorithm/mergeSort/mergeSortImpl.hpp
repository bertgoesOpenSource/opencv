#include <stdio.h>
#include <vector>

using namespace std;

class mergeSortImpl{
public:
  mergeSortImpl(){};
  vector<int> sort(vector<int>&);
  vector<int> merge(vector<int>, vector<int>);
  void split(vector<int>, vector<int>&, vector<int>&);
  void print(vector<int>);
  
};
