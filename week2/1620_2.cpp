#include <iostream>
#include <cctype> //isdigit
#include <string>
#include <unordered_map>

using namespace std;

int main(){ //112ms
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int total_num= 0, quiz_num = 0;
  cin >> total_num >> quiz_num;

  string pocket_dict[total_num];
  unordered_map<string,int> pocket_dict_eng;

  string pocketmon = "";
  for(int i = 0; i < total_num; i++){
    cin >> pocketmon;
    pocket_dict[i] = pocketmon;
    pocket_dict_eng.insert(make_pair(pocketmon,i+1));
  }

  string quiz_arr[quiz_num];
  for(int i = 0; i < quiz_num; i++){
    cin >> quiz_arr[i];
  }

  for(int i = 0; i < quiz_num; i++){
    if(isdigit(quiz_arr[i][0])) cout << pocket_dict[stoi(quiz_arr[i])-1] << '\n';
    else{
      cout << pocket_dict_eng[quiz_arr[i]] << '\n';
    }
  }

  return 0;
}

/* 124ms
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int total_num= 0, quiz_num = 0;
  cin >> total_num >> quiz_num;

  string pocket_dict[total_num];
  unordered_map<string,int> pocket_dict_eng;

  string pocketmon = "";
  for(int i = 0; i < total_num; i++){
    cin >> pocketmon;
    pocket_dict[i] = pocketmon;
    pocket_dict_eng.insert(make_pair(pocketmon,i+1));
  }

  for(int i = 0; i < quiz_num; i++){
    cin >> pocketmon;
    if(isdigit(pocketmon[0])) cout << pocket_dict[stoi(pocketmon)-1] << '\n';
    else{
      cout << pocket_dict_eng[pocketmon] << '\n';
    }
  }

  return 0;
}
*/