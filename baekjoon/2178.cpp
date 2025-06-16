#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[100][100];
int visited[100][100];
int dy[4] = {-1,0,1,0}, dx[4] = {0, 1, 0, -1};
int m,n;

typedef struct{
  int y;
  int x;
  int depth;
} Node;

int func(){
  queue<Node> q;
  visited[0][0] = 1;
  q.push({0,0,1});
  

  while(q.size()){
    Node now = q.front();q.pop();
    Node next;
    for (int i = 0; i < 4; i++)
    {
      next.y = now.y + dy[i];
      next.x = now.x + dx[i];
      next.depth = now.depth + 1;

      if(next.y >= n || next.x >= m || next.y < 0 || next.x < 0) continue;
      if(map[next.y][next.x] != 1) continue;
      if(visited[next.y][next.x]) continue;
      if(next.y == n-1 && next.x == m-1) return next.depth;
      visited[next.y][next.x] = 1;
      q.push(next);
    }
  }

  return -1;
}



int main(){
  string row;
  fill(&visited[0][0], &visited[0][0] + 100*100, 0);
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> row;
    for(int j = 0; j < m; j++){
      map[i][j] = row[j]-'0';
    }
  }
  
  cout << func();

}