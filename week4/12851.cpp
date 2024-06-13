#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100001];
long long cnt[100001];

void find_answer(){
  queue<int> q;
  q.push(N);
  visited[N] = 1;
  cnt[N] = 1;

  int current;
  while(q.size()){
    current = q.front(); q.pop();
    for(int next:{current-1, current+1, current*2}){
      if(next >= 0 && next <= 100000){
        if(!visited[next]){
          q.push(next);
          visited[next] = visited[current] + 1;
          cnt[next] = cnt[current];
        }else if(visited[next] == visited[current]+1){
          cnt[next] += cnt[current];
        }
      }
    }
  }
}

int main(){
  cin >> N >> K;

  find_answer();
  cout << visited[K]-1 << "\n" << cnt[K];
  return 0;
}