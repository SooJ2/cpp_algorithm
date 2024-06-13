#include <iostream>
#include <queue>
#include <tuple>

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
    if(current == K) return;
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
}//3192KB

/*
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int N, K, answer_depth;
long long answer_count;
long long visited[100001];
int visited_depth[100001];

void find_shortest(){
  queue<pair<int,int>> q;

  visited[N] = 1;
  visited_depth[N] = 0;
  int depth = 0, curr = N;
  q.push({depth,curr});
  while(q.size()){
    tie(depth,curr) = q.front(); q.pop();
    if(curr == K){
      answer_depth = depth;
      answer_count = visited[curr];
      return;
    }else{
      if((curr-1) >= 0){
        if(visited[curr-1] && visited_depth[curr-1] == depth+1){
          visited[curr-1]+=visited[curr];
        }
        else if (!visited[curr-1]){
          visited[curr-1] = visited[curr];
          visited_depth[curr-1] = depth+1;
          q.push({depth+1,curr-1});
        }
      }
      if((curr+1) <= 100000){
        if(visited[curr+1] && visited_depth[curr+1] == depth+1){
          visited[curr+1]+=visited[curr];
        }
        else if (!visited[curr+1]){
          visited[curr+1] = visited[curr];
          visited_depth[curr+1] = depth+1;
          q.push({depth+1,curr+1});
        }
      }
      if(curr*2 <= 100000){
        if(visited[curr*2] && visited_depth[curr*2] == depth+1){
          visited[curr*2] += visited[curr];
        }
        else if(!visited[curr*2]){
          visited[curr*2] = visited[curr];
          visited_depth[curr*2] = depth+1;
          q.push({depth+1,curr*2});
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N >> K;

  find_shortest();

  cout << answer_depth << "\n" << answer_count << "\n";
}//3456KB

*/