#include <iostream>
#include <vector>


using namespace std;
int num;
vector<char> signs;
string min_answer = "", max_answer = "";
bool already[10] = {false,};

bool calculate(int i, char sign, int j){
  if(sign == '<') return i < j;
  else if(sign == '>') return i > j;
  return false;
}

void solution(int index, string curr){
  if(index == num){
    if(min_answer.length() == 0){
      min_answer = curr;
    }else{
      max_answer = curr;
    }
    return;
  }
  for(int i = 0; i < 10; i++){
    if(already[i]) continue;
    if(curr.length() == 0 || calculate(curr[index]-'0',signs[index],i)){
      already[i] = true;
      solution(index+1,curr+to_string(i));
      already[i] = false;
    }
  }
}

int main(){
  cin >> num;

  for(int i = 1; i <= num; i++){
    char input;
    cin >> input;
    signs.push_back(input);
  }

  solution(-1,"");
  
  cout << max_answer << endl;
  cout << min_answer << endl;
}