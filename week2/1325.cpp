#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
int N,M;
// map<int,vector<int>> relationship;
map<int,set<int>> relationship;
map<int,set<int>> parents;
// map<int,int> child_map;
int check[10000];
int maximum = 0;
vector<int> IDs;


// int find_childs(int node,bool start){
//   check[node] = 1;

//   if(relationship.find(node) == relationship.end()) return 1;
  
//   int childs;
//   if(start) childs = 0;
//   else childs = 1;


//   for(int i: relationship[node]){
//     if(check[i]) continue;
//     childs += find_childs(i,false);
//   }

//   return childs;
// }

int main(){
  cin >> N >> M; // #N computer, #M input
  while(M){
    int A,B;
    cin >> A >> B;
    M--;
    if(!check[B]){
      set<int> s;
      s.insert(A);
      relationship[B] = s;
      check[B] = 1;
      
    }else{
      relationship[B].insert(A);
    }
    if(check[A]){
      for(int i : relationship[A]){
        relationship[B].insert(i);
      }
    }
    
    if(parents.find(A)==parents.end()){
      parents[A] = {B};
    }else{
      parents[A].insert(B);
    }

    if(check[B]){
      for(int i : parents[B]){
        relationship[i].insert(A);
      }
    }
  }

  // for(pair p: relationship){
  //   cout << p.first << "] " << p.second.size() << endl;
  //   for(int i : p.second){
  //     cout << i << " ";
  //   }cout << endl;
  //   if(p.second.size()>maximum){
  //     IDs.clear();
  //     maximum = p.second.size();
  //     IDs.push_back(p.first);
  //   }else if(p.second.size() == maximum){
  //     IDs.push_back(p.first);
  //   }
  // }

  // for(pair p: relationship){
  //   fill_n(check,10000,0);
  //   child_map[p.first] = find_childs(p.first,true);
  //   if(child_map[p.first] == maximum) IDs.push_back(p.first);
  //   else if(child_map[p.first] > maximum){
  //     maximum = child_map[p.first];
  //     IDs.clear();
  //     IDs.push_back(p.first);
  //   }
  // }

  for(pair p: relationship){
    if(p.second.size()>maximum){
      IDs.clear();
      maximum = p.second.size();
      IDs.push_back(p.first);
    }else if(p.second.size() == maximum){
      IDs.push_back(p.first);
    }
  }


  for(int ID: IDs){
    cout << ID << " ";
  }
  cout << "\n";

}