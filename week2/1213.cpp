#include <iostream>
#include <map>

using namespace std;

int main(){
  string name;
  cin >> name;

  map<char,int> alphabets;
  for(char c: name){
    if(alphabets.count(c) != 0){
      alphabets[c] += 1;
    }else{
      alphabets[c] = 1;
    }
  }
  string output = name;
  int mid = name.length() / 2;
  int odd_count = 0, front = 0, back = name.length()-1;
  for(auto alphabet:alphabets){
    if(alphabet.second % 2 != 0 ){
      odd_count += 1;
      if(odd_count > 1){
        cout << "I'm Sorry Hansoo";
        return 0;
      }
      output[mid] = alphabet.first;
    }
    for(int i = 0; i < alphabet.second / 2; i++){
      output[front] = alphabet.first;
      front++;
      output[back] = alphabet.first;
      back--;
    }
  }
  cout << output;

}