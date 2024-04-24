#include <iostream>

using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int N, M;
int map[100][100]; int polluted_map [100][100];

void BFS(int y, int x){
  polluted_map[y][x] = 1;
  cout << "(" <<  y << ", " << x << ")" << " polluted!!" << endl;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    cout << "\t()" << ny << ", " << nx << ") check" << endl;
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if (map[ny][nx] == 0 || polluted_map[ny][nx] == 1) continue;
    BFS(ny,nx);
  }
}

int main(){
  int input;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> input;
      map[i][j] = input;
    }
  }
  //init
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      polluted_map[i][j] = 0;
    }
  }
  int x,y,count = 0;
  for (y = 0; y < N; y++){
    for (x = 0; x < M; x++){
      if(polluted_map[y][x] || !map[y][x]) continue;
      cout << "------BFS!------" << endl;
      BFS(y,x);
      count ++;
    }
  }

  cout << count << endl;

}