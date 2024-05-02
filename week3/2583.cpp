#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;
int M,N,R;
int map[100][100];
int visited[100][100];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void DFS(int y, int x, int *area){
  visited[y][x] = 1;
  *area += 1;
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
    if(map[ny][nx] || visited[ny][nx]) continue;
    DFS(ny,nx,area);
  }
}


int main(){
  cin >> M >> N >> R;
  int lx,ly,rx,ry;
  while(R){
    cin >> lx >> ly >> rx >> ry;  
    for(int i = ly; i < ry; i++){
      for(int j = lx; j < rx; j++){
        map[i][j] = 1;
      }
    }
    R--;
  }

  int count = 0;
  vector<int> areas;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++){
      if(map[i][j] || visited[i][j]) continue;
      int area = 0;
      DFS(i, j, &area);
      areas.push_back(area);
      count++;
    }
  }
  cout << count << endl;
  sort(areas.begin(),areas.end());
  for(int area: areas){
    cout << area << " ";
  }
}