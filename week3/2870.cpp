#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
vector<int> digits;

// void find_digit(string input){
//   int start = 0, prev = -1;
//   for(int i = 1; i <= input.length(); i++){
//     // cout << start << "," << i <<": [" <<input.substr(start,i) << "] " << atoi(input.substr(start,i).c_str()) <<endl;
//     if((atoi(input.substr(start,i).c_str()) == 0) && input.substr(start,i) != "0"){
//       if(prev != -1) digits.push_back(prev);
//       cout << ">>>" <<  input.substr(start,i) << endl;
      
//       start = i;
//       prev = -1;
//       continue;
//     }
//     prev = atoi(input.substr(start,i).c_str());
//   }
//   if(prev != -1) digits.push_back(prev);
// }

// void find_digit(string input){
//   // for(int i = 0; i < input.length(); i++){

//   // }
//   int start = 0, len = 1, prev = -1;
//   while(start < input.length() && len <= input.length()){
//     // cout << start << "," <<len <<": [" <<input.substr(start,len) << "] " << atoi(input.substr(start,len).c_str()) <<endl;
//     if(atoi(input.substr(start,len).c_str()) == 0 && input.substr(start,len) != "0"){
//       //not a digit
//       if(prev != -1){
//         digits.push_back(prev);
//       }
//       start = start+len;
//       len = 1; prev = -1;
//       continue;
//     }
//     prev = atoi(input.substr(start,len).c_str());
//     len++;
//   }
//   if(prev != -1){
//     digits.push_back(prev);
//   }
// }

void find_digit(string input){

  int start = 0, len = 1, prev = -1;
  for(int i = 0; i < input.length(); i++){
    // cout << start << "," <<len <<": [" <<input.substr(start,len) << "] " << atoi(input.substr(start,len).c_str()) <<endl;
    if(isdigit(input[i])== 0 && input.substr(start,len) != "0"){
      //not a digit
      if(prev != -1){
        digits.push_back(prev);
      }
      start = start+len;
      len = 1; prev = -1;
      continue;
    }
    prev = atoi(input.substr(start,len).c_str());
    len++;
  }
  if(prev != -1){
    digits.push_back(prev);
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

  sort(digits.begin(), digits.end());
  for(int digit: digits){
    cout << digit << endl;
  }

}