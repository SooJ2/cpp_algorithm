#include <iostream>
#include <vector>

using namespace std;

int R, C;
char lake[1500][1500];
bool visited[1500][1500];

vector<pair<int,int>> swan;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};

void find_answer(int y, int x){
  visited[y][x] = true;

  int ny,nx;
  for(int i = 0; i < 4; i++){
    ny = y + dy[i]; nx = x + dx[i];
    if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    if(visited[ny][nx]) continue;
    visited[ny][nx] = true;
    if(lake[ny][nx] == 'X'){
      lake[ny][nx] = '.';
      continue;
    }
    find_answer(ny,nx);
  }
}

bool still_apart(int y, int x){
  visited[y][x] = true;
  bool cont = true;
  int ny, nx;
  for(int i = 0; i < 4; i++){
    ny = y + dy[i]; nx = x + dx[i];
    // cout << "[" <<  ny << ", " << nx << "]\n";
    if(ny == swan[1].first && nx == swan[1].second){
      // cout << "FOUND: " << ny << ", " << nx << "\n"; 
      return false;
    }
    if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    if(visited[ny][nx]) continue;
    if(lake[ny][nx] != '.') continue;
    visited[ny][nx] = true;
    if(!still_apart(ny, nx)) return false;
  }
  return true;
}

int main(){
  cin >> R >> C;
  string input;
  for(int i = 0; i < R; i++){
    cin >> input;
    for(int j = 0; j < C; j++){
      lake[i][j] = input[j];
      if(input[j] == 'L') swan.push_back({i,j});
    }
  }

  int answer = 0;

  bool still = still_apart(swan[0].first,swan[0].second);
  while(still){
    // cout <<"CONT " << answer << "\n";
  // while(answer < 3){
    fill(&visited[0][0], &visited[0][0]+2250000,0);

    for(int i = 0; i < R; i++){
      for(int j = 0; j < C; j++){
        if(lake[i][j] != '.') continue;
        if(visited[i][j]) continue;
        find_answer(i,j);
      }
    }

    // cout << "\n";
    // for(int i = 0; i < R; i++){
    //   for(int j = 0; j < C; j++){
    //     cout << lake[i][j];
    //   }cout << "\n";
    // }

    fill(&visited[0][0], &visited[0][0]+2250000,0);

    still = still_apart(swan[0].first,swan[0].second);
    // cout << "STILL " << still << "\n";
    answer++;
  }

  std::cout << answer;
}

/*
8 17
...XXXXXX..XX.XXX
....XXXXXXXXX.XXX
...XXXXXXXXXXXX..
..XXXXX..XXXXXX..
.XXXXXX..XXXXXX..
XXXXXXX...XXXX...
..XXXXX...XXX....
....XXXXX.XXX....

*/