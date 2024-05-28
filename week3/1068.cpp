#include <iostream>
#include <vector>
#include <map>


using namespace std;
int node_num;
map<int,vector<int>> nodes;
map<int,int> parent;
vector<int>del_nodes;

void delete_nodes(int del){
  if(nodes[del].size() == 0){
    vector<int>::iterator it = find(nodes[parent[del]].begin(),nodes[parent[del]].end(),del);
    nodes[parent[del]].erase(it);
    nodes.erase(del);
    return;
  }
  // for(int i = 0; i < nodes[del].size(); i++){
  //   delete_nodes(nodes[del][i]);
  //   // nodes[del].erase(nodes[del].begin()+i);
  // }

  while(nodes[del].size()){
    delete_nodes(nodes[del][0]);
  }

  cout << del << " <- "<<parent[del] << "\n";
  vector<int>::iterator it = find(nodes[parent[del]].begin(),nodes[parent[del]].end(),del);
  nodes[parent[del]].erase(it);
  
  
  nodes.erase(del);
}

int main(){
  cin >> node_num;
  for(int i = 0; i < node_num; i++){
    vector<int> v;
    nodes.insert({i,v});
    int input;
    cin >> input;
    parent[i] = input;

    if(input < 0) continue;
    nodes[input].push_back(i);
  }

  // for(pair p: nodes){
  //   cout << p.first << "] ";
  //   for(int i: p.second){
  //     cout << i << " ";
  //   }
  //   cout << "\n";
  // }

  int del, answer = 0;
  cin >> del;
  if(del != 0){
    delete_nodes(del);
    for(pair p: nodes){
      if(p.second.size()) answer ++;
    }
  }

  cout << answer<<"\n";
}