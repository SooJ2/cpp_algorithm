#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, ny, nx;
char board[20][20];
int visited[20][20], alphabet[26];
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
vector<int> answers;
string input;

void find_answer(int y, int x, int depth){
  visited[y][x] = 1;
  alphabet[board[y][x]-'A'] = 1;
  int count = 0;
  for(int i = 0; i < 4; i++){
    ny = y + dy[i]; nx = x + dx[i];
    if(ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
    if(visited[ny][nx] || alphabet[board[ny][nx]-'A']) continue;
    count++;
    find_answer(ny,nx,depth+1);
  }
  
  if(count == 0){
    answers.push_back(depth);
  }
  visited[y][x] = 0;
  alphabet[board[y][x]-'A'] = 0;

}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> R >> C;
  for(int i = 0 ; i < R; i++){
    cin >> input;
    for(int j = 0; j < C; j++){
      board[i][j] = input[j];
    }
  }

  find_answer(0,0,1);

  cout << *max_element(answers.begin(), answers.end());
}//584ms

/*
20 20
IEFCJIIIIIIIIIIIIIII
FHFKCIIIIIIIIIIIIIII
FFALFIIIIIIIIIIIIIII
HFGCFIIIIIIIIIIIIIII
HMCHHIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
*/