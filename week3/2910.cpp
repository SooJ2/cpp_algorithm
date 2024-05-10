#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int N,C;

bool compare(pair<int,int> prev, pair<int,int> curr){
  return prev.second > curr.second;
}

int main(){
  cin >> N >> C;
  int input;
  vector<int> ex_num;
  vector<int> count;

  while(N){
    cin >> input;
    vector<int>::iterator iter;
    if((iter = find(ex_num.begin(),ex_num.end(),input)) != ex_num.end()){
      count[iter-ex_num.begin()]++;
    }else{
      ex_num.push_back(input);
      count.push_back(1);
    }
    N--;
  }

  vector<pair<int,int>> nums;
  for(int i  = 0 ; i < ex_num.size(); i++){
    nums.push_back({ex_num[i],count[i]});
  }

  stable_sort(nums.begin(),nums.end(),compare);

  for(int j = 0; j < nums.size(); j++){
    for(int i = 0; i < nums[j].second; i++){
      if(j == 0 && i == 0) cout << nums[j].first;
      else cout <<" "<< nums[j].first;
    }
  }
}