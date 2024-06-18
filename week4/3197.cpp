#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int R, C;
char lake[1500][1500];
bool visited[1500][1500];
bool visited_swan[1500][1500];

vector<pair<int,int>> swan;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
queue<pair<int,int>> water;
queue<pair<int,int>> s, ns;

void find_answer(){
  //melting
  int water_size = water.size();
  int y, x, ny, nx;
  while(water_size){
    tie(y,x) = water.front(); water.pop();
    water_size--;
    // cout << y << ", " << x << "\n";
    for(int i = 0; i < 4; i++){
      ny = y + dy[i]; nx = x + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if(visited[ny][nx]) continue;

      if(lake[ny][nx] == 'X'){
        visited[ny][nx] = true;
        lake[ny][nx] = '.';
        water.push({ny,nx});
      }
    }
  }
}

bool move(){
  int y, x, ny, nx;

  while(s.size()){
    tie(y,x) = s.front(); s.pop();
    for(int i = 0; i < 4; i++){
      ny = y + dy[i]; nx = x + dx[i];
      if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
      if(visited_swan[ny][nx]) continue;
      visited_swan[y][x] = true;

      if(lake[ny][nx] == 'X'){
        ns.push({ny,nx});
      }
      else if(lake[ny][nx] == 'L'){
        return true;
      }
      else{
        s.push({ny,nx});
      }
    }
  }
  return false;
}

void clearQ(queue<pair<int,int>> &q){
  queue<pair<int,int>> empty;
  swap(q,empty);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> R >> C;
  string input;
  for(int i = 0; i < R; i++){
    cin >> input;
    for(int j = 0; j < C; j++){
      lake[i][j] = input[j];
      if(input[j] == '.'|| input[j] == 'L'){
        visited[i][j] = true; 
        water.push({i,j});
      }
      if(input[j] == 'L') swan.push_back({i,j});
    }
  }

  s.push({swan[0].first,swan[0].second});
  visited_swan[swan[0].first][swan[0].second] = true;

  int answer = 0;
  while(true){
    if(move()) break;
    s = ns;
    clearQ(ns);

    find_answer();

    answer++;
  }

  std::cout << answer;
}