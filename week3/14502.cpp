#include <iostream>

using namespace std;

int N,M,maximum = 0;
int map[8][8];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int find_safe_area(int** polluted_map){
  int safe_area = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(polluted_map[i][j] == 0) safe_area++;
    }
  }
  return safe_area;
}

void DFS(int y, int x, int ** polluted_map){
  polluted_map[y][x] = 2;
  for(int i = 0; i < 4; i++){
    int ny,nx;
    ny = y + dy[i]; nx = x + dx[i];
    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if(polluted_map[ny][nx] != 0) continue;
    DFS(ny,nx,polluted_map);
  }
}

void pollute(){
  int **polluted_map = new int*[8];
  for(int i = 0; i < N; i++){
    polluted_map[i] = new int[8];
    for(int j = 0; j < M; j++){
      polluted_map[i][j] = map[i][j];
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(map[i][j] != 2) continue;
      DFS(i,j,polluted_map);
    }
  }

  int safe_area = find_safe_area(polluted_map);
  if(safe_area > maximum) maximum = safe_area;
  return;
}

void find_solution(int walls){
  if(walls == 3){
    pollute();
    return;
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if (map[i][j] != 0) continue;
      map[i][j] = 1;
      find_solution(walls+1);
      map[i][j] = 0;
    }
  }

}

int main(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> map[i][j];
    }
  }

  find_solution(0);

  cout << maximum << "\n";
}
