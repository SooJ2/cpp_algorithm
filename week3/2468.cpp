#include <iostream>

using namespace std;
int N; 
int map[100][100];
int visited[100][100];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1}; 

void DFS(int y, int x, int h){
  visited[y][x] = 1;
  for(int i =0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if(visited[ny][nx] || map[ny][nx] <= h) continue;
    DFS(ny,nx,h);
  }
}

int main(){
  cin >> N;  

  int max = -1;
  for (int i = 0; i < N; i++){
    for (int j = 0; j< N; j++){
      cin >> map[i][j];
      if(map[i][j] > max) max = map[i][j];
    }
  }

  int prev_m = 0, cur = 0;
  for(int r = 0; r < max; r++) { 
    cur = 0;
    for (int i = 0; i < N; i++){
      for (int j = 0; j< N; j++){
        if(map[i][j] <= r || visited[i][j]) continue;
        DFS(i,j,r);
        cur++;
      }
    }
    if(cur > prev_m) prev_m = cur;

    for(int k = 0; k < N; k++){
      fill_n(visited[k],N,0);
    }
  }
  cout << prev_m << endl;
}