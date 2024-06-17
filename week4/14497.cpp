#include <iostream>
#include <tuple>

using namespace std;

int N,M;
int jx,jy,tx,ty;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int class_map[300][300];
int visited[300][300];

bool find_answer(int y, int x){
  int nx, ny;
  for(int i = 0; i < 4; i++){
    ny = y + dy[i]; nx = x + dx[i];
    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    if(visited[ny][nx]) continue;
    if(class_map[ny][nx] == 4) return false;
    
    visited[ny][nx] = 1;
    if(class_map[ny][nx] == 1){
      class_map[ny][nx] = 0;
      continue;
    }
    if(!find_answer(ny,nx)) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M;

  cin >> jy >> jx >> ty >> tx;
  jx--;jy--;tx--;ty--;

  string input;
  for(int i = 0; i < N; i++){
    cin >> input;
    for(int j = 0; j < M; j++){
      if(input[j] == '*') class_map[i][j] = 3;
      else if(input[j] == '#') class_map[i][j] = 4;
      else class_map[i][j] = input[j] - '0';
    }
  }

  if(jy == ty && jx == tx) return 0;

  bool cont = true;
  int answer = 0;
  while(cont){
    fill(&visited[0][0], &visited[0][0]+90000, 0);
    visited[jy][jx] = 1;
    cont = find_answer(jy,jx);
    answer++;
  }
  cout << answer;
}//64ms