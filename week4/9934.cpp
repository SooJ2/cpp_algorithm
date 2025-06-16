#include <iostream>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

int K;
int buildings[1025], visited[1025];
queue<pair<int,int>> answer;
//1 ~ 2^K-1


void find_answer(int left, int right){
  answer.push({left,right});
  // int i, mid_l, mid_r ,
  int answer_size = answer.size();
  int l, r, mid;
  while(answer_size){
    tie(l, r) = answer.front(); answer.pop();
    answer_size--;
    mid = l + int(r-l)/2; 
    // cout << "[" << l << ", " << r << "] " << mid << "\n";
    if(visited[mid]) continue;

    visited[mid] = 1;
    cout << buildings[mid] << " ";
    if(l == r) continue;

    answer.push({l,mid-1});// [)
    answer.push({mid+1,r});

  
    if(answer_size == 0){
      cout << "\n";
      answer_size = answer.size();
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> K;
  for(int i = 0; i < pow(2,K)-1; i++){
    cin >> buildings[i];
  }

  find_answer(0,pow(2,K)-2);
}

/*

5
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

*/