#include <iostream>
#include <map>

using namespace std;

int main(){
  int fee[4] = {0,};
  for(int i = 1; i < 4; i++ ){
    cin >> fee[i];
  }

  int timeline[100] = {0,};

  int in, out;
  for(int i = 0; i < 3; i++){
    cin >> in >> out;
    for(int j = in; j < out; j++){
      timeline[j-1] += 1;
    }
  }

  int total = 0;
  for(int i = 0; i < 100; i++){
    total += timeline[i]*fee[timeline[i]];
  }
  cout << total<< endl;
  
}