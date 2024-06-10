#include <iostream>
#include <vector>

using namespace std;

int N, L, R;
int A[50][50], visited[50][50];
vector<pair<int,int>> u;
int u_sum = 0;

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

bool find_union(int y, int x, int depth){
  visited[y][x] = 1;
  u_sum += A[y][x];
  u.push_back({y,x});

  int ny, nx;
  for(int i = 0; i < 4; i++){
    ny = y + dy[i]; nx = x + dx[i];
    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
    if(visited[ny][nx]) continue;
    if(L <= abs(A[y][x] - A[ny][nx]) && abs(A[y][x] - A[ny][nx]) <= R)
      find_union(ny, nx, depth+1);
  }

  if(depth == 0 && u.size()){
    int cal = int(u_sum / u.size());
    for(pair<int,int> p: u){
      A[p.first][p.second] = cal;
    }
  }
  return u.size() > 1 ? true : false;
}

int main(){
  cin >> N >> L >> R;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> A[i][j];
    }
  }

  int trial = 1, answer = 0;
  while(trial){
    fill(&visited[0][0],&visited[0][0]+50*50,0);
    trial = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(visited[i][j]) continue;
        u_sum = 0;
        u.clear();
        trial += find_union(i,j,0);
      }
    }
    if(trial)
      answer += 1;
  }

  cout << answer << "\n";
}