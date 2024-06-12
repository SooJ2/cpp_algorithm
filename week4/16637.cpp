#include <iostream>
#include <vector>

using namespace std;

int N;
string input;
vector<char> cal;
int find_answer(int prev, int nxt, char c){
  if(c == '+') return prev + nxt;
  else if(c == '-') return prev - nxt;
  else return prev * nxt;
}


int calculate(int i, int answer){
  int first = -999999999, second = -999999999, tmp;
  if(i == 0){
    first = cal[i]-'0';
    if(N >= 3){
      second = find_answer(cal[i]-'0',cal[i+2]-'0',cal[i+1]);
    }
  }else{
    first = find_answer(answer,cal[i]-'0',cal[i-1]);
    if(i+2 < N){
      tmp = find_answer(cal[i]-'0',cal[i+2]-'0',cal[i+1]);
      second = find_answer(answer,tmp,cal[i-1]);
    }
  }
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
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> input;
  for(int i = 0; i < N; i++){
    cal.push_back(input[i]);
  }
  cout << calculate(0,0) << "\n";
}