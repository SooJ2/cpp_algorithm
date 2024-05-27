#include <iostream>

using namespace std;

int M,N;
int **map, **next_map, **visited;
int cheese, prev_cheese = 0;

int dy[4] = {-1,0,1,0}, dx[4] ={0,1,0,-1};

void find_edge(int y, int x){
  // cout << "\tCHECK " << y << ", " << x << "\n";
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
  // cout << "CHECK " << y << "," << x << "\n";
  visited[y][x] = 1; //true
  if(map[y][x] == 1)
    next_map[y][x] = 1;
  bool will_be_melted = false;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    // if(y==11){
    //   cout << "  " << y << "," << x << ")NEXT: "<<ny <<", "<<nx<<"\n";
    // }
    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    // cout << "AFTER MAG CHECK" << "\n";
    if(map[ny][nx] == 2){
      will_be_melted = true;
      // cout << y <<"," << x <<" will be melted\n";
      continue;
    }
    if(visited[ny][nx]) continue;
    // cout << "AFTER VISIT CHECK" << "\n";
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
  map = new int*[N];
  next_map = new int*[N];

  visited = new int*[N];
  for(int i = 0; i < N; i++){
    map[i] = new int[M];
    next_map[i] = new int[M];


    visited[i] = new int[M];
    for(int j = 0; j < M; j++){
      cin >> map[i][j];
      if(map[i][j]) cheese++;
    }
  }

  //아예 치즈가 없는 겨우도 생각해보기
  int trial = 0;
  while(cheese > 0){
    // cout << cheese << "\n";

  // while(trial < 10){

    // cout << trial << "] " << cheese <<"\n";
    //visited 초기화
    for(int i = 0; i < M; i++){
      fill_n(visited[i],M,0);
    }
    //map swap
    if(trial != 0){
      for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
          map[i][j] = next_map[i][j];
        }
      }
    }

    // cout << "FIND EDGE" << "\n";
    find_edge(0,0);
    // for(int i = 0; i < N; i++){
    //   for(int j = 0; j < M; j++){
    //     cout << map[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    //visited 초기화
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

    // for(int i = 0; i < N; i++){
    //   for(int j = 0; j < M; j++){
    //     cout << next_map[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
  }

  cout << trial << "\n";
  cout << prev_cheese << "\n";

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