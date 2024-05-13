#include <iostream>
#include <cctype>
#include <vector>

using namespace std;
vector<string> digits;

string check_zero(string digit){
  while(digit[0] == '0' && digit.length() > 1){
    digit = digit.substr(1,digit.length());
  }
  return digit;
}

void put_digit_in_digits(string digit){
  vector<string>::iterator iter;
  for(iter = digits.begin(); iter != digits.end(); iter++){
    if(digit.length() < ((string)*iter).length()){
      digits.insert(iter,digit);
      break;
    }else if(((string)*iter).length() == digit.length()){      
      if(digit < ((string)*iter)){
        digits.insert(iter,digit);
        break;
      }     
    }
  }
  if(iter == digits.end()) digits.push_back(digit);
}

void find_digits(string input){
  string digit = "";
  for(char c: input){
    if(isdigit(c) == 0 && c != '0'){
      //not a digit
      if(digit != ""){
        if(digits.size() == 0) digits.push_back(check_zero(digit));
        else{
          //put digit in digits on proper index
          put_digit_in_digits(check_zero(digit));
        }
        digit = "";
      }
    }else{
      digit += c;
    }
  }
  if(digit != ""){
    if(digits.size() == 0) digits.push_back(check_zero(digit));
    else{
      //put digit in digits on proper index
      put_digit_in_digits(check_zero(digit));
    }
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

  for(string digit: digits){
    cout << digit << endl;
  }
}