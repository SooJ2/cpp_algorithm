#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int N, K;
int visited[100001];
int prev_path[100001];

void find_answer(){
  queue<int> q;
  q.push(N);

  visited[N] = 1;
  prev_path[N] = -1;

  int current;
  while(q.size()){
    current = q.front(); q.pop();

    for(int next: {current-1, current+1, current*2}){

      if(next >= 0 && next <= 100000){
        if(visited[next]) continue;
        q.push(next);
        visited[next] = visited[current]+1;
        prev_path[next] = current;
        if(next == K) return;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> K;

  find_answer();
  cout << visited[K] -1 << "\n";

  int answer_path[visited[K]];
  int output = K, trial = visited[K]-1;
  while(output != -1){
    answer_path[trial--] = output;
    output = prev_path[output];
  }

  for(int i = 0; i < visited[K]; i++){
    cout << answer_path[i] << " ";
  }
  cout << "\n";
}//12ms