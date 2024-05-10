#include <iostream>

using namespace std;
int N,M;
int main(){
  cin >> N >> M;
  
  int b_left = 1; int b_right = M;

  int count,move,total_move = 0;
  cin >> count;
  int apple;
  while(count){
    cin >> apple;
    if(apple < b_left){
      move = b_left - apple;
      b_left = b_left - move;
      b_right = b_right - move;
      total_move += move;
    }else if(apple > b_right){
      move = apple - b_right;
      b_right = b_right + move;
      b_left = b_left + move;
      total_move += move;
    }
    count--;
  }
  cout << total_move;
}