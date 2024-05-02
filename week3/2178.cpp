#include <iostream>
#include <vector> //include <utility> // for pair
#include <queue>
#include <string>

using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int map[100][100]; int visited[100][100];
int N,M;


void BFS(pair<int,int> p){
  queue<pair<int,int>> q;
  q.push(p);
  visited[p.first][p.second] = 1;
  while(q.size()){
    pair<int,int> tmp_node = q.front();
    q.pop();
    for(int i = 0; i < 4; i++){
      int ny = tmp_node.first + dy[i];
      int nx = tmp_node.second + dx[i];
      if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
      if(map[ny][nx] == 0 || visited[ny][nx]) continue;
      q.push({ny,nx});
      visited[ny][nx] = visited[tmp_node.first][tmp_node.second] + 1;
      if(ny == N-1 && nx == M-1){
        cout << visited[ny][nx];
        return;
      }
    }
  }

}

int main(){
  cin >> N >> M;
  cin.ignore();
  pair<int,int> start = {0,0};
  for(int i = 0; i < N; i++){
    string input;
    getline(cin,input);
    for(int j = 0; j < M; j++){
      map[i][j] = stoi(input.substr(j,1));
    }
  }
  BFS(start);
}
