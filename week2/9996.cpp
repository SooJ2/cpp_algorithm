#include <iostream>
#include <vector>
using namespace std;

//G
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int file_num; string input;
  cin >> file_num;
  cin >> input;
  vector<string> pattern = split(input,"*");
  string pref = pattern[0], suff = pattern[1];


  while(file_num){
    cin >> input;
    if(input.length() < pref.length() + suff.length()){
      cout << "NE" << endl;
    }else if (input.substr(0,pref.length()) == pref && input.substr(input.length()-suff.length()) == suff){
      cout << "DA" << endl;
    }else{
      cout << "NE" << endl;
    }
    
    file_num--;
  }
}