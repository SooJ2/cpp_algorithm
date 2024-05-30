#include <iostream>
#include <stack>

using namespace std;
int N;
int a[1000000];
int answer[1000000];
stack<int> remain;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;

  fill_n(answer,N,-1);
  for(int i = 0; i < N; i++){
    cin >> a[i];
    while(remain.size() && a[remain.top()] < a[i]){
      answer[remain.top()] = a[i];
      remain.pop();
    }
    remain.push(i);
  }

  for(int i = 0; i < N; i++){
    cout << answer[i] << " ";
  }

  return 0;
}