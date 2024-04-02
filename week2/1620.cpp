#include <iostream>
#include <cctype> //isdigit
#include <string>
#include <algorithm> //find
#include <map>

using namespace std;


int main(){
  int total_num= 0, quiz_num = 0;
  cin >> total_num >> quiz_num;
  string pocket_dict[total_num];
  map<string,int> pocket_dict_eng;
  string pocketmon = "";
  for(int i = 0; i < total_num; i++){
    cin >> pocketmon;
    pocket_dict[i] = pocketmon;
    pocket_dict_eng[pocketmon] = i+1;
  }

  string quiz;
  while(quiz_num){
    cin >> quiz;
    if(isdigit(quiz[0])) cout << pocket_dict[stoi(quiz)-1] << endl;
    else{
      cout << pocket_dict_eng[quiz] << endl;
    }
    quiz_num--;
  }

  return 0;
}

