#include <iostream>
#include <cmath>

using namespace std;

int find(int input){
  string tmp = "";
  long long count = 1, ones = 1;

  while(true){
    // cout << "ones: " << ones << ", count: " << count << " | ";
    if (ones % input == 0){
      return count;
    }
    ones = ones * 10 + 1;
    ones %= input;
    count ++;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int input = 0;
  while (!cin.eof()){
    cin >> input;
    cout << find(input) << endl;
  }

}