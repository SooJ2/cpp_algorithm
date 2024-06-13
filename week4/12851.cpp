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
  int depth = 0, curr = N;
  q.push({depth,curr});
  while(q.size()){
    tie(depth,curr) = q.front(); q.pop();
    // cout << depth  << " " << curr << "\n";
    if(curr == K){
      answer_depth = depth;
      // answer_count = 1;
      // // cout << "ADD FRIST " << answer_count << "\n";
      // while(q.size() && (depth = q.front().first ) == answer_depth){
      //   if(q.front().second == K) {
      //     answer_count++;
      //     // cout << "ADD " << answer_count << "\n";
      //   }
      //   cout << q.front().first << " "<< q.front().second << "\n";
      //   q.pop();
      // }
      // cout << "ANSWER" << curr << " " << visited[curr] << "\n";
      // for(int c: visited){
      //   cout << c <<" ";
      // }cout << "\n";
      answer_count = visited[curr];
      return;
    }else{
      // if((curr -1) * curr >= 0 || ((curr -1) * curr < 0 && (curr-1) * K > 0 )){
      if((curr-1) > 0 ){
        // cout << "SUB\n";
        if(visited[curr-1] && visited_depth[curr-1] == depth+1){
          visited[curr-1]+=visited[curr];
        }
        else{
          visited[curr-1] = visited[curr];
          visited_depth[curr-1] = depth+1;
          q.push({depth+1,curr-1});
        }
      }
      // if((curr +1) * curr >= 0 || ((curr +1) * curr < 0 && (curr+1) * K > 0 )){
      // if((curr+1) * K >= 0 ){
      if(visited[curr+1] && visited_depth[curr+1] == depth+1){
        visited[curr+1]+=visited[curr];
      }
      else{
        visited[curr+1] = visited[curr];
        visited_depth[curr+1] = depth+1;
        q.push({depth+1,curr+1});
      }
      // }
      // if(curr * K > 0){
      if(curr*2 <= 100000 && visited[curr*2] && visited_depth[curr*2] == depth+1){
        visited[curr*2] += visited[curr];
      }
      else if(curr*2 < 100000){
        // cout << "MUL\n";
        visited[curr*2] = visited[curr];
        visited_depth[curr*2] = depth+1;
        q.push({depth+1,curr*2});
      }
      // }

      // cout << "VISITED " <<visited[curr] << "\n";
    }
  }
  // cout << "END\n";

}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N >> K;
  // N=0;K=100000;
  // fill(visited,visited+100001,0);
  // cout << "ANSWER COUNT: " << answer_count << "\n";
  find_shortest();

  cout << answer_depth << "\n" << answer_count << "\n";
}