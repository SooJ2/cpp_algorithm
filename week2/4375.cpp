#include <iostream>
#include <cmath>

using namespace std;

int find(int input){
  string tmp = "";
  int count = to_string(input).length();
  tmp.append(count,'1');
  long long ones = stoll(tmp);
  tmp = "";
  tmp.append(count,'0'); tmp[0] = '1';
  long long trial = stoll(tmp);
  while(true){
    // cout << "ones: " << ones << ", trial: " << trial << " | ";
    if (ones % input == 0){
      return to_string(ones).length();
    }
    trial *= 10; 
    ones += trial;
  }
  return -1; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int input = 0;
  while (cin >> input){
    cout << find(input) << endl;
  }

}