#include <iostream>
#include <string>

using namespace std;

string ROT13(string input){
  string output;
  for (char alphabet: input){
    char change = alphabet;
    if (alphabet >= 'A' && alphabet <= 'Z'){
      if (alphabet <= 'M'){
        change = alphabet + 13;
      }
      else{
        int temp = static_cast<int>(alphabet);
        change = 'A' + (temp - 78);

      }
    }
    else if (alphabet >= 'a' && alphabet <= 'z'){
      if (alphabet <= 'm'){
        change = alphabet + 13;
      }
      else{
        int temp = static_cast<int>(alphabet);
        change = 'a' + (temp - 110);

      }
    }
    output += change;
  }
  return output;
}

int main(){
  string input;
  getline(cin,input,'\n');
  cout << ROT13(input);
  return 0;
}