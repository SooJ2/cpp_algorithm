#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, input;
vector<int> v;

int go(int idx, int sum){
  if(idx == N){
    return sum % 11;
  }
  return max(go(idx+1,sum+v[idx]),go(idx+1,sum));
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> input;
    v.push_back(input);
  }

  cout << go(0,0) << "\n";
}