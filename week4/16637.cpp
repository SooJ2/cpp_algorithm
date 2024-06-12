#include <iostream>
#include <vector>

using namespace std;

int N;
string input;
vector<char> cal;
int find_answer(int prev, int nxt, char c){
  cout << "CAL: "<< prev << " " << c << " " << nxt << "\n";
  if(c == '+') return prev + nxt;
  else if(c == '-') return prev - nxt;
  else return prev * nxt;
}


int calculate(int i, int answer){
  
  // cout << "[" << i << "]" <<answer << "\n";
  int first = 0, second = 0, tmp;
  if(i == 0){
    first = cal[i]-'0';
    if(N >= 3){
      second = find_answer(cal[i]-'0',cal[i+2]-'0',cal[i+1]);
    }
  }else{
    // (9 < cal[i])
    // cout << "CAL_first: "<< answer << " " << cal[i] << " " << cal[i+1] << "\n";
    first = find_answer(answer,cal[i]-'0',cal[i-1]);
    if(i+2 < N){
      tmp = find_answer(cal[i]-'0',cal[i+2]-'0',cal[i+1]);
      second = find_answer(answer,tmp,cal[i-1]);
    }
  }
  // cout << "FIRST: " << first <<" SECOND: " << second << "\n";
  int nothing = first, doing = second;
  if(i+2 < N){
    nothing = calculate(i+2, first);
  }
  if(i+4 < N){
    doing = calculate(i+4, second);
  } 
  return max(nothing, doing);
}

int main(){
  cin >> N >> input;
  for(int i = 0; i < N; i++){
    cal.push_back(input[i]);
  }

  cout << calculate(0,0) << "\n";

}