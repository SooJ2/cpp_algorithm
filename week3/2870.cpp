#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
vector<string> digits;

void find_digit(string input){

  int start = 0, len = 1;
  string prev = "";
  for(int i = 0; i < input.length(); i++){
    // cout << start << "," <<len <<": [" <<input.substr(start,len) << "] " << atoi(input.substr(start,len).c_str()) <<endl;
    if(isdigit(input[i])== 0 && input.substr(start,len) != "0"){
      //not a digit
      if(prev != ""){
        while(prev[0] == '0' && prev.length() > 1) prev = prev.substr(1,prev.length()-1);
        if(digits.size() ==0) digits.push_back(prev);
        else{
          //자리찾아서
          int j;
          for(j = 0; j < digits.size(); j++){
            if(prev.length() < digits[j].length()){
              digits.insert(digits.begin()+j,prev);
              break;
            }else if (prev.length() == digits[j].length()){
              int k;
              for(k = 0; k < prev.length(); k++){
                if(prev[k] < digits[j][k]){
                  digits.insert(digits.begin()+j,prev);
                  break;
                }
              }
              // if(k==prev.length())continue;
              if(k != prev.length()) break;

            }
          }
          if(j==digits.size()) digits.push_back(prev);
        }
      }
      start = i+1;
      len = 1; prev = "";
      continue;
    }
    prev = input.substr(start,len);
    len++;
  }
  if(prev != ""){
    while(prev[0] == '0' && prev.length() > 1) prev = prev.substr(1,prev.length()-1);
    if(digits.size() ==0) digits.push_back(prev);
    else{
      //자리찾아서
      int j;
      for(j = 0; j < digits.size(); j++){
        if(prev.length() < digits[j].length()){
          digits.insert(digits.begin()+j,prev);
          break;
        }else if (prev.length() == digits[j].length()){
          int k;
          for(k = 0; k < prev.length(); k++){
            if(prev[k] < digits[j][k]){
              digits.insert(digits.begin()+j,prev);
              break;
            }
          }
          // if(k==prev.length())digits.insert(digits.begin()+j+1,prev);
          if(k != prev.length()) break;
        }
      }
      if(j==digits.size()) digits.push_back(prev);
    }
  }
}

int main(){
  int total;
  cin >> total;

  string input;
  while(total){
    cin >> input;
    find_digit(input);
    total--;
  }

  // sort(digits.begin(), digits.end());

  for(string digit: digits){
    cout << digit << endl;
  }

}