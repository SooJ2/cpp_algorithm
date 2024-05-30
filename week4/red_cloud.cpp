#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N, input;

int check(int sum){
  if(sum<=1) return 0;
  if(sum==2) return 1;
  if(sum%2 == 0) return 0;
  for(int i = 2; i < int(sqrt(sum))+1; i++){
    if(sum % i == 0) return 0;
  }
  return 1;
}

int go(int idx, int sum){
  if(idx == N) return check(sum);

  return go(idx+1,sum+v[idx]) + go(idx+1,sum);
}

int main(){

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> input;
    v.push_back(input);
  }

  cout << go(0,0) << endl;
}