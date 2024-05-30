#include <iostream>
#include <vector>
// #include <map>
#include <algorithm>
#include <string.h>

using namespace std;
int N,M;
int child_map[10001];
int check[10001];
int maximum = 0;
int A,B;
vector<int> relationship[10001];


int find_childs(int node){
  check[node] = 1;
  int childs = 1;
  for(int i: relationship[node]){
    if(check[i]) continue;
    childs += find_childs(i);
  }
  return childs;
}

int main(){

  ios_base::sync_with_stdio(0); 
  cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M; // #N computer, #M input
  while(M--){
    cin >> A >> B;
    relationship[B].push_back(A);
  }


  for(int i = 1; i <= N; i++){
    // fill_n(check,10000,0);
    memset(check,0,sizeof(check));
    child_map[i] = find_childs(i);
    maximum = max(child_map[i],maximum);
  }



  for(int i = 1; i <= N; i++){
    if(maximum == child_map[i]) cout << i << " ";
  }

  return 0;
}