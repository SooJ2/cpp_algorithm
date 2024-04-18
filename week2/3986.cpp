#include <iostream>
#include <stack>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int num;
  cin >> num;
  
  string word; int answer = 0;
  while(num){
    cin >> word;
    stack<char> char_stack;
   for(char c: word){
    if(char_stack.empty() || char_stack.top() != c){
      char_stack.push(c);
    }
    else{
      char_stack.pop();
    }
   }
   if (char_stack.empty()){
    answer++;
   }
    num--;
  }
  cout << answer;
}