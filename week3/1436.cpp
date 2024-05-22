#include <iostream>
#include <string>

using namespace std;

int find_title(int N){
  int i = 665;
  while(N){
    i++;
    if (to_string(i).find("666") != string::npos) N--;    
  }
  return i;
}

int main(){
  int N;
  cin >> N;
  cout << find_title(N) << '\n';
}