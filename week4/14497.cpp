#include <iostream>
#include <tuple>

using namespace std;

int N,M;
int jx,jy,tx,ty;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int class_map[300][300];
int visited[300][300];

bool find_answer(int y, int x){
  // if(y==ty && x == tx){

  //   return false;
  // }
  // cout << "JUSUNG " << jy << " " << jx << "\n";
  int nx, ny;
  for(int i = 0; i < 4; i++){
    ny = y + dy[i]; nx = x + dx[i];
    // cout << "[" << ny << "," << nx << "]\n";
    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
    // cout << "not overflow\n";
    if(visited[ny][nx]) continue;
    // cout << "not visited\n";
    if(class_map[ny][nx] == 4) return false;
    
    visited[ny][nx] = 1;
    if(class_map[ny][nx] == 1){
      // cout << "FRIEND " << ny << " " << nx << "\n";
      class_map[ny][nx] = 0; //visited 처리
      continue;
    }
    if(!find_answer(ny,nx)) return false;
  }
  return true;
}

int main(){
  cin >> N >> M;
  // cout << "\n" << N << " " << M << "\n";

  cin >> jy >> jx >> ty >> tx;
  jx--;jy--;tx--;ty--;

  // cout << "\n";
  // cout << jy << " " << jx << "\n";
  // cout << ty << " " << tx << "\n";
  // cout << "\n";

  string input;
  for(int i = 0; i < N; i++){
    cin >> input;
    for(int j = 0; j < M; j++){
      if(input[j] == '*') class_map[i][j] = 3;
      else if(input[j] == '#') class_map[i][j] = 4;
      else class_map[i][j] = input[j] - '0';
    }
  }

  // for(int i = 0; i < N; i++){
  //   for(int j = 0; j < M; j++){
  //     cout << class_map[i][j];
  //   }cout << "\n";
  // }
  // cout << "input fin\n";

  if(jy == ty && jx == tx) return 0;

  bool cont = true;
  int answer = 0;
  while(cont){
    fill(&visited[0][0], &visited[0][0]+90000, 0);
    visited[jy][jx] = 1;
    cont = find_answer(jy,jx);
    answer++;
    // cout << answer << "\n";
    // for(int i = 0; i < N; i++){
    //  for(int j = 0; j < M; j++){
    //     cout << class_map[i][j];
    //   }cout << "\n";
    // } 
  }
  cout << answer;
}