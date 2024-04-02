#include <iostream>
#include <cctype> //isdigit
#include <string>
#include <map>

using namespace std;

int total_num, quiz_num;
string pocketmon;
string pocket_dict[100004];
map<string,int> pocket_dict_eng;

int main(){ //160ms
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> total_num >> quiz_num;
  for(int i = 0; i < total_num; i++){
    cin >> pocketmon;
    pocket_dict[i + 1] = pocketmon;
    pocket_dict_eng[pocketmon] = i + 1;
  }

  for(int i = 0; i < quiz_num; i++){
    cin >> pocketmon;
    if(atoi(pocketmon.c_str()) == 0){
      cout << pocket_dict_eng[pocketmon] << '\n';
    }
    else{
      cout << pocket_dict[atoi(pocketmon.c_str())] << '\n';
    }
  }
}

