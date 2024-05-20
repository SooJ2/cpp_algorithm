#include <iostream>

using namespace std;

int main(){
  int T,N;
  cin >> T;
  while(T){
    cin >> N;
    cout << int(N/5) << endl;
    T--;
  }
}