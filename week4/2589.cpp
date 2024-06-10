#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int N,M;

char treasure_map[50][50];
int visited[50][50];

int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int treasure_dist = 0;


int find_treasure(int y, int x){
  int max_length = 0;
  queue<pair<int,int>> q;
  visited[y][x] = 0;
  q.push({y,x});

  int qy, qx;
  while(q.size()){
    tie(qy,qx) = q.front(); q.pop();
    for(int i = 0; i < 4; i++){
      int ny = qy + dy[i], nx = qx + dx[i];
      if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if(treasure_map[ny][nx] == 'W') continue;
      if(visited[ny][nx] >= 0) continue;
      visited[ny][nx] = visited[qy][qx] + 1;
      if(visited[ny][nx] > max_length) max_length = visited[ny][nx];
      q.push({ny,nx});
    }
  }
  return max_length;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N >> M;
  string input;
  for(int i = 0; i < N; i++){
    cin >> input;
    for(int j = 0; j < M; j++){
      treasure_map[i][j] = input[j];
    }
  }
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(treasure_map[i][j] == 'W') continue;
      fill(&visited[0][0], &visited[0][0] + 50 * 50, -1);
      treasure_dist = max(treasure_dist,find_treasure(i,j));
    }
  }

  cout << treasure_dist;
}