#include <iostream>
#include <stack>

using namespace std;

string is_VPS(string input){
  stack<char> s;
  for(char c: input){
    if(c == '(') s.push(c);
    else{
      if(s.size()) s.pop();
      else return "NO";
    }
  }
  if(s.size()) return "NO";
  return "YES";
}

int main(){
  int test;
  cin >> test;
  for(int i = 1; i <= test; i++){
    string input;
    cin >> input;
    cout << is_VPS(input) << "\n";
  }
  return 0;
}