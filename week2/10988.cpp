#include <iostream>
#include <algorithm> // reverse

using namespace std;

int main(){
  string word;
  cin >> word;
  string reversed_word = word;
  reverse(reversed_word.begin(),reversed_word.end());
  word == reversed_word? cout << 1 : cout << 0;
}