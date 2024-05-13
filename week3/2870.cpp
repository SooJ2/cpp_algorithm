#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> digits;

bool cmp(string a, string b){
  if(a.length() == b.length()){
    return a < b;
  }
  return a.length() < b.length();
}

string check_zero(string digit){
  while(digit[0] == '0' && digit.length() > 1){
    digit = digit.substr(1,digit.length());
  }
  return digit;
}

void find_digits(string input){
  string digit = "";
  for(char c: input){
    if(isdigit(c) == 0 && c != '0'){
      //not a digit
      if(digit != ""){
        digits.push_back(check_zero(digit));
        digit = "";
      }
    }else{
      digit += c;
    }
  }
  if(digit != ""){
    digits.push_back(check_zero(digit));
  }
}



int main(){
  int total;
  cin >> total;

  string input;
  while(total){
    cin >> input;
    find_digits(input);
    total--;
  }

  sort(digits.begin(), digits.end(),cmp);
  for(string digit: digits){
    cout << digit << endl;
  }
}