#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int N,M;
map<int,vector<int>> relationship;
map<int,int> child_map;
int check[10000];
int maximum = 0;
vector<int> IDs;


int find_childs(int node,bool start){
  cout <<  node << endl;
  check[node] = 1;
  // if(relationship[node].size() == 0) return 1;
  // if(find(relationship.begin(),relationship.end(),node) == relationship.end()) return 1;
  if(relationship.find(node) == relationship.end()) return 1;
  
  int childs;
  if(start) childs = 0;
  else childs = 1;

  // for(int i = 0; i < relationship[node].size(); i++){
  //   if(check[i]) continue;//visited
  //   cout << "VISIT "<<relationship[node][i] << endl;
  //   childs += find_childs(relationship[node][i],false);
  // }

  for(int i: relationship[node]){
    if(check[i]) continue;
    childs += find_childs(i,false);
  }

  return childs;
}

int main(){
  cin >> N >> M; // #N computer, #M input
  while(M){
    int A,B;
    cin >> A >> B;
    M--;
    if(!check[B]){
      vector<int> v;
      v.push_back(A);
      relationship[B] = v;
      check[B] = 1;
      continue;
    }
    relationship[B].push_back(A);
  }

  //추가
  // for(int i = 0; i < relationship.size(); i++){
  //   fill_n(check,10000,0);
  //   cout << "["<<<"]"<<endl;
  //   child_map[i] = find_childs(i,true);
  // }

  for(pair p: relationship){
    fill_n(check,10000,0);
    cout << "[" << p.first << "] ";
    child_map[p.first] = find_childs(p.first,true);
  }


  for(pair p: relationship){
    cout << p.first << "] ";
    for(int i:p.second){
      cout << i << " ";
    }cout << endl;
  }
  cout << endl;
  for(pair p: child_map){
    cout << p.first << "] " << p.second <<endl;
  }


  // for(pair p: relationship){
  //   cout << p.first << "] SIZE: " << p.second.size() << endl;
  //   for(int i:p.second){
  //     cout << i << " ";
  //   }cout << endl;
  //   if(p.second.size() > maximum){
  //     maximum = p.second.size();
  //     IDs.clear();
  //     IDs.push_back(p.first);
  //   }else if(p.second.size() == maximum){
  //     IDs.push_back(p.first);
  //   }
  // }

  // for(int ID: IDs){
  //   cout << ID << " ";
  // }
  // cout << "\n";

}