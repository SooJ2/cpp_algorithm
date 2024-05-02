#include <iostream>
#include <vector>

using namespace std;
int N;
int map[64][64];

string quad_tree(pair<int,int> start, pair<int,int> end, int depth){ //yx yx
  // if(start.first < 0 || start.second < 0 || end.first < 0 || end.second < 0){
  //   cout<< "ERROR: " << start.first << ", "<< start.second << endl;
  //   return "";
  // }
  // if(start.first >= end.first  || start.second >= end.second ){
  //   cout<< "ERROR_start: " << start.first << ", "<< start.second << endl;
  //   cout<< "ERROR_end: " << end.first << ", "<< end.second << endl;

  //   return "";
  // }
  if((end.first - start.first) == 1){
    // cout << "RET: " << start.first << "," << start.second << endl;
    return to_string(map[start.first][start.second]);
  }
  // cout << "NOOP]" <<end.first <<" - " << start.first << " = " << end.first-start.first << endl;
  int mid_y = start.first + (end.first-start.first)/2;
  int mid_x = start.second + (end.second-start.second)/2;
  string second_qud = quad_tree(start,{mid_y,mid_x},depth+1); // yx
  string first_qud = quad_tree({start.first,mid_x},{mid_y,end.second},depth+1);
  string third_qud = quad_tree({mid_y,start.second},{end.first,mid_x},depth+1);
  string fourth_qud = quad_tree({mid_y,mid_x},end,depth+1);

  if(second_qud.length()==1 && second_qud == first_qud && second_qud == third_qud && second_qud == fourth_qud){
    // if(depth == 1) return "(" + second_qud + ")";
    // else return second_qud;
    return second_qud;
  } else{
    return "(" + second_qud + first_qud + third_qud + fourth_qud + ")";
  }
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    string tmp_input;
    cin >> tmp_input;
    for(int j = 0; j < N; j++){
      map[i][j] = tmp_input[j] - '0';
    }
  }
  // cout << "START!!!" << endl;
  cout <<  quad_tree({0,0}, {N,N}, 1) << endl;

}