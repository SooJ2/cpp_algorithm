#include <iostream>
#include <queue>

using namespace std;
int N, K;
int visited[2][500001];

int find_answer(){
  if(N==K) return 0;
  queue<int> q;
  q.push(N);
  visited[0][N] = 1;
  int depth = 0;
  while(q.size()){
    int qsize = q.size();
    if (K+(depth)*(2+depth-1)/2 > 500000) break;
    if(visited[depth%2][K+(depth)*(2+depth-1)/2]) return depth;
    while(qsize){
      int curr = q.front(); q.pop();
      for(int next: {curr-1, curr+1, curr*2}){
        // cout <<depth << "]" << curr << " " << next << "\n";
        if(next >= 0 && next <= 500000){
          if(visited[(depth+1)%2][next]) continue;
          visited[(depth+1)%2][next] = 1;
          q.push(next);
          if(next == K+(depth+1)*(2+depth)/2) return depth+1;
        }
      }
      qsize--;
    }
    depth++;
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  cin >> N >> K;
  cout << find_answer() << "\n";
}//12ms