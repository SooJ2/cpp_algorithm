#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N,M;
  cin >> N >> M;

  int input_num, output = 0;
  vector<int> nums;

  for(int i = 0; i < N; i++){
    cin >> input_num;
    for(int number: nums){
      if (input_num + number == M) output += 1;
    }
    nums.push_back(input_num);
  }

  cout << output;
}