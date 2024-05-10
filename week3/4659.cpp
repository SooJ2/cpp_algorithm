#include <iostream>
#include <algorithm>

using namespace std;
char vowels[] = {'a','e','i','o','u'}; // consonant
bool test(string input){
    int cont_vow = 0, cont_cons = 0, vow_count = 0;
    char prev_c = 'A';
    for(char c : input){
      if(find(vowels,vowels+5,c) != vowels+5){
        cont_vow += 1;
        cont_cons = 0;
        vow_count += 1;
      }else{
        cont_cons += 1;
        cont_vow = 0;
      }
      if(cont_vow >= 3){
        return false;
      }
      if(cont_cons >= 3){
        return false;
      } 
      if(prev_c == c && (c != 'e' && c != 'o')) return false;

      prev_c = c;      
    }
    if(vow_count <= 0){
      return false;
    }
    return true;
}

int main(){
  string input = "";
  cin >> input;

  while(input != "end"){
    if(test(input)){
      cout << "<" << input << "> is acceptable." << endl;
    }else{
      cout << "<" << input << "> is not acceptable." << endl;
    }
    cin >> input;
  }
}