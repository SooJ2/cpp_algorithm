#include <iostream>
#include <vector>

using namespace std;
int N;
int a[1000000];
int answer[1000000];
vector<int> remain;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }
  fill_n(answer,N,-1);

  for(int i = 0; i < N; i++){
    vector<int>::iterator it = remain.begin();
    while(it != remain.end()){
      // cout << "["<< *it <<"] "<< a[*it]<< " ";
      if(a[*it] < a[i]){
        answer[*it] = a[i];
        remain.erase(it);
      }else{
        it++;
      }
    }
    // cout << "\n";
    remain.push_back(i);
  }

  for(int i = 0; i < N; i++){
    cout << answer[i] << " ";
  }

  return 0;
}