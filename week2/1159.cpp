#include <iostream>
#include <set>

using namespace std;

int main(){
  int num_of_student;
  cin >> num_of_student;

  int student_name_count[26] = {0,};
  set<char> answer;

  for(int i = 0; i < num_of_student; i++){
    string name;
    cin >> name;
    int idx = name[0]-'a';
    if(++student_name_count[idx] == 5){
      answer.insert(name[0]);
    }
  }

  for(set<char>::iterator iter = answer.begin(); iter != answer.end(); iter++){
    cout << *iter;
  }

  if(answer.size() == 0)
    cout << "PREDAJA";

}