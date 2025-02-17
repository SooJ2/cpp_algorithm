#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;
char **m; bool **visited;
int R, C;
pair<int,int> J; vector<pair<int,int>> Fs;
int curr_depth;

int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void fire_spread(int cd){
  int ny, nx;
  vector<pair<int,int>> new_Fs(Fs);
  Fs.clear();
  for(pair<int,int> p: new_Fs){
    for(int i = 0; i < 4; i++){
      ny = p.first + dy[i]; nx = p.second + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if(m[ny][nx] == 'F' || m[ny][nx] == '#') continue;
      m[ny][nx] = 'F';
      Fs.push_back({ny,nx});
    }
  }

  curr_depth = cd;
}

bool find_way(int y, int x, int depth){
  queue<pair<int,int>> q;
  queue<int> d;
  visited[y][x] = true;
  q.push({y,x}); d.push(0);

  int cy, cx, cd, ny, nx;
  while(q.size()){
    cy = q.front().first; cx = q.front().second; cd = d.front();
    q.pop(); d.pop();
    if(curr_depth != cd){
      fire_spread(cd);
    }
    if(m[cy][cx] == 'F') continue;
    if(cy == 0 || cy == R-1 || cx == 0 || cx == C-1){
      //answer
      cout << cd + 1 << "\n";
      return true;
    }

    for(int i = 0; i < 4; i++){
      ny = cy + dy[i]; nx = cx + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if(m[ny][nx] != '.') continue;
      if(visited[ny][nx]) continue;
      visited[ny][nx] = true;
      q.push({ny,nx}); d.push(cd+1);
    }

  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> R >> C;
  m = new char*[R];
  visited = new bool*[R];
  for(int i = 0; i < R; i++){
    m[i] = new char[C];
    visited[i] = new bool[C];
  }

  string input;
  for(int i = 0; i < R; i++){
    cin >> input;
    for(int j = 0; j < C; j++){
      m[i][j] = input[j];
      if(m[i][j] == 'J') J = {i,j};
      else if(m[i][j] == 'F') Fs.push_back({i,j});
    }
  }


  if(!find_way(J.first,J.second,0)) cout << "IMPOSSIBLE" << "\n";

  //delete
  for(int i = 0; i < R; i++){
    delete m[i];
    delete visited[i];
  }
  delete m;
  delete visited;

  return 0;
}//32ms