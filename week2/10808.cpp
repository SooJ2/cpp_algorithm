#include <iostream>
using namespace std;

int main()
{
  string word;
  cin >> word;
  int alphabets[26] = {0,};
  for(char e: word){
    alphabets[e-97] += 1;
  }
  for(int i = 0; i < 26; i++){
    cout << alphabets[i] << " ";
  }
}