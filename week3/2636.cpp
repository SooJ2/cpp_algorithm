#include <iostream>

using namespace std;

int M,N;
int map[100][100], next_map[100][100], visited[100][100];
int cheese, prev_cheese = 0;

int dy[4] = {-1,0,1,0}, dx[4] ={0,1,0,-1};

void find_edge(int y, int x){
  visited[y][x] = 1;
  map[y][x] = 2;
  next_map[y][x] = 2;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if(visited[ny][nx] || map[ny][nx] == 1) continue;
    find_edge(ny,nx);
  }
}

void melting_cheese(int y, int x){
  visited[y][x] = 1; //true
  if(map[y][x] == 1)
    next_map[y][x] = 1;
  bool will_be_melted = false;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];

    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if(map[ny][nx] == 2){
      will_be_melted = true;
      continue;
    }
    if(visited[ny][nx]) continue;
    if(map[ny][nx] != 1) continue;
    melting_cheese(ny,nx);
  }
  if(will_be_melted){
    cheese--;
    next_map[y][x] = 2;
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> map[i][j];
      if(map[i][j]) cheese++;
    }
  }

  int trial = 0;
  while(cheese > 0){

    for(int i = 0; i < M; i++){
      fill_n(visited[i],M,0);
    }

    if(trial != 0){
      for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
          map[i][j] = next_map[i][j];
        }
      }
    }

    find_edge(0,0);

    for(int i = 0; i < M; i++){
      fill_n(visited[i],M,0);
    }

    prev_cheese = cheese;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(map[i][j] != 1) continue;
        if(visited[i][j] == 1) continue;
        melting_cheese(i,j);
      }
    }
    trial++;


  }

  cout << trial << "\n";
  cout << prev_cheese << "\n";

  return 0;
}

/*
6 6
0 0 0 0 0 0
0 0 0 1 1 0
0 1 1 0 1 0
0 1 1 1 0 0
0 1 1 1 0 0
0 0 0 0 0 0


6 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
*/