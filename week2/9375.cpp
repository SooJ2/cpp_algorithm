#include <iostream>
#include <map>

using namespace std;

int main(){
  //total test case num
  int test_case_num;
  cin >> test_case_num;

  //parts
  int parts_num;
  while(test_case_num){
    cin >> parts_num;
    map<string,int> parts;
    while(parts_num){
      string name, part;
      cin >> name; 
      cin >> part;
      if (parts.count(part) != 0){
        parts[part] += 1;
      }else{
        parts.insert({part,1});
      }
      parts_num--;
    }

  
    int fact = 1;

    for(auto num: parts){
      fact *= (num.second+1);
    }    
    
    cout << fact - 1 << endl;

    test_case_num--;
  }
}