#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int tomato[1000][1000];
int minimum[1000][1000];
int m, n, answer = -1;
int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

typedef struct{
  int y;
  int x;
}Node;

queue<Node> q;

void find_answer(){

  while(q.size()){
    Node now = q.front(); q.pop();
    Node next;
    for (int i = 0; i < 4; i++)
    {
      next.y = now.y + dy[i];
      next.x = now.x + dx[i];
      if(next.y >= n || next.x >= m || next.y < 0 || next.x < 0) continue;
      if(tomato[next.y][next.x] != 0) continue;
      if(minimum[next.y][next.x] <= minimum[now.y][now.x] + 1) continue;
      minimum[next.y][next.x] = minimum[now.y][now.x] + 1;
      q.push(next);
    }
    
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  bool already = true;
  cin >> m >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> tomato[i][j];
      if(already && tomato[i][j] == 0) already = false;
    }
  }

  if(already){
    answer = 0;
  }
  else{
    fill(&minimum[0][0], &minimum[0][0] + 1000*1000, 21e8);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(tomato[i][j] != 1) continue;
        q.push({i,j});
        minimum[i][j] = 0;        
      }
    }

    find_answer();

    bool fail = false;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if(tomato[i][j] != -1 && minimum[i][j] == 21e8){
          fail = true;
          answer = -1;
          break;
        }
        if(tomato[i][j] != -1) answer = max(answer,minimum[i][j]);
      }
      if(fail) break;
    }
    
  }
  cout << answer;

}

/*

3 3
0 0 -1
0 -1 0
0 -1 1


3 3
1 0 -1
0 -1 0
0 -1 1

3 3
0 -1 -1
-1 -1 0
1 -1 1

3 3
1 -1 -1
-1 -1 1
1 -1 1


3 3
-1 -1 -1
-1 -1 -1
-1 -1 -1
*/