#include <iostream>
#include <vector>

using namespace std;
int map[50][50];
int visited[50][50];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int N,M;

void DFS(int y, int x){
  visited[y][x] = 1;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if (!map[ny][nx] || visited[ny][nx]) continue;
    DFS(ny,nx);
  }
  return;
}

int main(){
  int TC;
  cin >> TC;
  while(TC){
    int total;
    cin >> M >> N >> total;
    for(int i = 0; i < N; i ++){
      for(int j = 0; j < M; j++){
        map[i][j] = 0;
      }
    } // init
    for(int i = 0; i < N; i ++){
      for(int j = 0; j < M; j++){
        visited[i][j] = 0;
      }
    } // init
    for(int i = 0; i < total; i++){
      int x,y;
      cin >> x >> y;
      map[y][x] = 1;
    }

    int count = 0;
    for(int i = 0; i < N; i ++){
      for(int j = 0; j < M; j++){
        if(!map[i][j]) continue;
        if(visited[i][j]) continue;
        count++;
        DFS(i,j);
      }
    }
    cout << count << endl;
    TC--;
  }
}