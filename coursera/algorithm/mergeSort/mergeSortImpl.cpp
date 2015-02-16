#include "mergeSortImpl.hpp"
#include <iostream>
using namespace std;

vector<int> mergeSortImpl::sort(vector<int>& curArray){
  if (curArray.size() == 1)
    return curArray;
  
  vector<int> left, right;
  //split Array in Half
  split(curArray,left, right);

  //recursively sort left and right
  vector<int> leftSorted = sort(left);
  vector<int> rightSorted = sort(right);

  //merge result
  vector<int> result = merge(leftSorted, rightSorted);
  return result;
  
}

vector<int> mergeSortImpl::merge(vector<int> left, vector<int> right){
  vector<int> result;
  vector<int>::iterator itL = left.begin();
  vector<int>::iterator itR = right.begin();
  while(itL!=left.end() && itR!=right.end()){
    if (*itL < *itR){
      result.push_back(*itL);
      itL++;
    }else{
      result.push_back(*itR);
      itR++;
    }
  }

  //end cases
  while(itL!=left.end()){
    result.push_back(*itL);
    itL++;
  }
  while(itR!=right.end()){
    result.push_back(*itR);
    itR++;
  }
  return result;
}

void mergeSortImpl::split(vector<int> arr, vector<int>& left, vector<int>& right){

  // split the array into halfes, if the size is odd, the left array will have one less element

  int size = arr.size()/2;
  vector<int>::iterator it = arr.begin();
  for(int i = 0;i < size; i++){
    left.push_back(*it++);
  }
  for(;it!=arr.end();it++){
    right.push_back(*it);
  }

  
}


void mergeSortImpl::print(vector<int> arr){
  vector<int>::iterator it = arr.begin();
  while(it!=arr.end()){
    cout<<*it<<endl;
    it++;
  }
      
}
int main(){
  vector<int> result;
  vector<int> array;
  array.push_back(3);
  array.push_back(2);
  array.push_back(6);
  array.push_back(1);
  array.push_back(-2);
  array.push_back(10);
  array.push_back(2);
  array.push_back(3);
  mergeSortImpl obj;
  result = obj.sort(array);
  obj.print(result);
  return 0;
}

