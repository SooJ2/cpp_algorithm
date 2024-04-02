#include <iostream>
#include <numeric> // accumulate
#include <queue>

using namespace std;
/*시간: 32ms*/
int main(){

  int total, days;

  cin>> total >> days;
  
  int max = 0, curr = 0, new_num = 0;

  queue<int> temps;
  for(int i = 0; i < total; i++){
    cin >> new_num;
    temps.push(new_num);

    if (i < days-1){
      curr += new_num;
    }
    else if (i == days-1){
      curr += new_num;
      max = curr;
    }
    else{
      curr -= temps.front();
      temps.pop();
      curr += new_num;
      if (curr > max) max = curr;
    }
  }

  cout << max;


} 

/* 시간: 404ms
#include <iostream>
#include <numeric> // accumulate
#include <vector>

using namespace std;

int main(){

  int total, days;

  cin>> total >> days;
  
  int max = 0, curr = 0, new_num = 0;

  vector<int> temps;
  for(int i = 0; i < total; i++){
    cin >> new_num;
    temps.push_back(new_num);

    if (i < days-1) continue;
    else if (i == days-1){
      max = accumulate(temps.begin(),temps.end(),0);
      curr = max;
    }
    else{
      curr -= temps.front();
      temps.erase(temps.begin());
      curr += new_num;
      if (curr > max) max = curr;
    }
  }

  cout << max;


} 
*/