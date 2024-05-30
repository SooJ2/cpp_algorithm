#include <iostream>
#include <vector>

using namespace std;

int a[3][3] ={
    {10, 20, 21},
    {70, 90, 12},
    {80, 110, 120}
  };
int visited[3][3];
vector<int> money;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void earn_money(int y, int x, int sum){
  if(y == 2 && x == 2){
    money.push_back(sum);
    return;
  }
  for(int i = 0; i < 4; i++){
    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 0 || ny >= 3 || nx < 0 || nx >= 3) continue;
    if(visited[ny][nx]) continue;
    visited[ny][nx] = true;
    earn_money(ny,nx,sum+a[ny][nx]);
    visited[ny][nx] = false;
  }
  return;
}

int main(){
  visited[0][0] = 1;
  earn_money(0,0,a[0][0]);

  for(int i : money){
    cout << i << " ";
  }
}