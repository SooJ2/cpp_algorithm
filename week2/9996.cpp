#include <iostream>
#include <vector>
using namespace std;

vector<string> split(string input, string delim){
  vector<string> output;
  long long index;
  while((index = input.find(delim)) != string::npos){
    output.push_back(input.substr(0,index));
    input.erase(0,index + delim.length());
  }
  if(!input.empty())
  {
    output.push_back(input);
  }

  return output;
}


int main(){
  int file_num; string input;
  cin >> file_num;
  cin >> input;
  vector<string> pattern = split(input,"*");
  string prev = pattern[0], end = ""; int size = pattern.size();
  if (size != 1){
    end = pattern[1];
  }

  while(file_num){
    cin >> input;
    if (size == 1){
      if (input.substr(input.length()-prev.length()) == prev){
        cout << "DA" << endl;
      }else{
        cout << "NE" << endl;
      }
    }else{
      if (input.substr(0,prev.length()) == prev && input.substr(input.length()-end.length()) == end){
        cout << "DA" << endl;
      }else{
        cout << "NE" << endl;
      }
    }
    file_num--;
  }
}