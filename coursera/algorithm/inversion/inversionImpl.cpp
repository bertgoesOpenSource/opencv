#include "inversionImpl.hpp"
#include <iostream>
#include <fstream>

using namespace std;

ulong inversionImpl::sortAndCount(vector<int>& curArray){
  if (curArray.size() == 1)
    return 0;
  
  vector<int> left, right;
  //split Array in Half
  split(curArray,left, right);
  
  //recursively count left, right, and split inversions
  ulong leftTotal = sortTrivialAndCount(left);
  
  ulong rightTotal = sortTrivialAndCount(right);
 
  ulong splitTotal = splitCount(curArray,left, right);
 
  return leftTotal+rightTotal+splitTotal;
  
}


ulong inversionImpl::sortTrivialAndCount(vector<int>& array){
  if (array.size() == 1)
    return 0;
  if (array.size() == 2){
    if(array.at(0) > array.at(1)){
      // swap and count
      int temp = array.at(1);
      array.at(1) = array.at(0);
      array.at(0) = temp;
      return 1;
    }else{
      return 0;
    }
  }

  // recurse
  return sortAndCount(array);
  
}



ulong inversionImpl::splitCount(vector<int>& curArray,vector<int> left, vector<int> right){
  //vector<int> resultArr;
  ulong result = 0;
  vector<int>::iterator it = curArray.begin();
  vector<int>::iterator itL = left.begin();
  vector<int>::iterator itR = right.begin();
  while(itL!=left.end() && itR!=right.end()){
    if (*itL <= *itR){
      *it = *itL;
      itL++;
    }else{
      *it = *itR;
      itR++;
      result += left.end()-itL;
    }
    it++;
  }
  //increment curArray it;

	 //end cases
  while(itL!=left.end()){
    *it++ = *itL++;
    }
   
  while(itR!=right.end()){
    *it++ = *itR++;
    }
  
  return result;
}

void inversionImpl::split(vector<int> arr, vector<int>& left, vector<int>& right){

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


void inversionImpl::print(vector<int> arr){
  vector<int>::iterator it = arr.begin();
  while(it!=arr.end()){
    cout<<*it<<endl;
    it++;
  }
      
}

void inversionImpl::print(ulong out){
  
  cout<<"Result is "<<out<<endl;
}


int main(int argc, const char* argv[]){
  // vector<int> result;

  ifstream myfile(argv[1]);
  string line;
    vector<int> array;
  if(myfile.is_open()){
    while(!myfile.eof()){
      int num=0;
      myfile>>num;
      array.push_back(num);
    }
    array.pop_back();
  }
  else{
    cout << "Error loading file"<<endl;
  }
 
 
      
  inversionImpl obj;
   obj.print(array);

  ulong result = obj.sortAndCount(array);
   obj.print(result);
  return 0;
}

