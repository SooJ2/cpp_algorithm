#include <iostream>

using namespace std;

/*Again*/
long long cal(long long A, long long B, long long C){
  long long ret;
  if(B == 1) return A % C;
  ret = cal(A,B/2,C);
  ret = (ret * ret) % C;

  if(B % 2){
    ret = (ret * A) % C;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  long long A, B, C, answer = 1;
  cin >> A >> B >> C;

  cout << cal(A,B,C);
}