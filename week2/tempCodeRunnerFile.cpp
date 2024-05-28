#include <iostream>
#include <vector>
// #include <map>
#include <algorithm>
#include <string.h>

using namespace std;
int N,M;
// map<int,vector<int>> relationship;
// map<int,int> child_map;
int child_map[10000];
int check[10000];
int maximum = 0;
// vector<int> IDs;
vector<int> relationship[10000];


int find_childs(int node){
  int childs = 1;
  for(int i: relationship[node]){
    if(check[i]) continue;
    check[node] = 1;
    childs += find_childs(i);
  }

  return childs;
}

int main(){

  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> N >> M; // #N computer, #M input
  while(M--){
    int A,B;
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