#include <iostream>
#include <queue>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[100][100];
int map[100][100];
int M,N,cy,cx;

void BFS(int y, int x){
  queue<int> qy,qx; // pairt<int,int>사용가능 
  qy.push(y); qx.push(x); // q.push({y,x})
  visited[y][x] = 1;

  while(qy.size()){
    int ty = qy.front(), tx = qx.front();
    qy.pop(); qx.pop();
    for (int i = 0; i < 4; i++)
    {
      int ny = ty + dy[i];
      int nx = tx + dx[i];
      if(ny < 0 || ny >= 100 || nx < 0 || nx >= 100) continue;
      if(map[ny][nx] == 0) continue;
      visited[ny][nx] = visited[ty][tx] + 1;
      if(ny == cy && nx == cx){
        cout << "[TOTAL] 당근 "<< visited[ny][nx] << "개 소모!" << endl;
        return;
      } 
      qy.push(ny); qx.push(nx);
    }
  }
  

}

int main(){
  cin >> N >> M;

  int y,x;
  cin >> y >> x;
  cin >> cy >> cx;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> map[i][j];
    }
  }
  BFS(y,x);
}