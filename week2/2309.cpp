#include <iostream>
#include <vector> 
#include <numeric> //accumulate
#include <algorithm> //sort
int tall[9];

using namespace std;

bool make_combination(int n, int r, int start, vector<int> ret){
  if(ret.size() == r){
    if(accumulate(ret.begin(),ret.end(),0) == 100){
      sort(ret.begin(),ret.end());
      for (int element: ret){
        cout << element << endl;
      }
      return true;
    }
    return false;
  }

  bool find = false;
  for(int i = start; i < n; i++){
    ret.push_back(tall[i]);
    find = make_combination(n,r,i+1,ret);
    if (find)
      break;
    ret.pop_back();
  }
  return find;
}

int main(){
  for(int i = 0; i < 9; i++){
    cin >> tall[i];
  }
  // combination
  vector<int> tmp;
  make_combination(9,7,0,tmp);
}