#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T,N;
  cin >> T;
  for(int k = 0; k < T; k++){
    cin >> N;
    int answer = 0;
    for(int i = 5; i <= N; i *= 5){
      answer += (N/i);
    }
    cout << answer << "\n";
  }
}

// int n, a;
// int main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   cin >> n;
//   for(int i = 0; i < n; i++){
//     cin >> a;
//     int ret5 = 0;
//     for(int j = 5; j <= a; j *= 5){
//       ret5 += a / j;
//     }
//     cout << ret5 << "\n";
//   }
// }