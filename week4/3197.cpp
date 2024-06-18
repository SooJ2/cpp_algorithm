#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4]  = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[1501][1501], visited_swan[1501][1501], R, C, y, x, answer, swan_x, swan_y;
char lake[1501][1501];

queue<pair<int,int>> water, nwater, s, ns;
string input;

void qclear(queue<pair<int,int>> &q){
  queue<pair<int,int>> empty;
  swap(q,empty);
}

void find_answer(){
  while(water.size()){
    tie(y,x) = water.front(); 
    water.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i]; 
      int nx = x + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;
      if(lake[ny][nx] == 'X'){
        visited[ny][nx] = 1;
        nwater.push({ny,nx});
        lake[ny][nx] = '.';
      }
    }
  }
}

bool move(){
  while(s.size()){
    tie(y,x) = s.front(); 
    s.pop();
    for(int i = 0; i < 4; i++){
      int ny = y + dy[i]; 
      int nx = x + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx]) continue;
      visited_swan[y][x] = 1;
      if(lake[ny][nx] == '.') s.push({ny,nx});
      else if(lake[ny][nx] == 'X') ns.push({ny,nx});
      else if(lake[ny][nx] == 'L') return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  cin >> R >> C;
  for(int i = 0; i < R; i++){
    cin >> input;
    for(int j = 0; j < C; j++){
      lake[i][j] = input[j];
      if(lake[i][j] == 'L') {swan_y = i; swan_x = j;}
      if(lake[i][j] == '.'|| lake[i][j] == 'L') visited[i][j] = 1,water.push({i,j});
    }
  }

  s.push({swan_y,swan_x});
  visited_swan[swan_y][swan_x] = 1;
  while(true){
    if(move()) break;
    find_answer();
    water = nwater;
    s = ns;
    qclear(nwater);
    qclear(ns);
    answer++;
  }
  cout << answer << "\n";
}