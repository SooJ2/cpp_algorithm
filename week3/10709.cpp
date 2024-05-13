#include <iostream>

using namespace std;
int H,W;
int map[100][100];

int main(){
  cin >> H >> W;
  string input;
  for(int i = 0; i < H; i++){
    cin >> input;
    int cloud = -1;
    for(int j = 0; j < W; j++){
      if(input[j] == 'c'){
        cloud = 0;
        map[i][j] = cloud;
      }else if(cloud != -1){
        map[i][j] = ++cloud;
      }else{
        map[i][j] = -1;
      }
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}