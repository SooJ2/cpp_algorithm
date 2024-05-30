#include <iostream>
// #include <map>
#include <vector>

using namespace std;

int N,M;
int town_map[50][50];

vector<pair<int,int>> houses;
vector<pair<int,int>> chiken_stores;

vector<int> selected_store;
int city_chiken_dist = 1e8;

void cal_city_chiken_dist(){
  int tmp_city_chiken_dist = 0;
  for(int h = 0; h < houses.size(); h++){
    int chiken_dist = 1e8;
    for(int c: selected_store){
      chiken_dist = min(chiken_dist,abs(chiken_stores[c].first-houses[h].first)+abs(chiken_stores[c].second-houses[h].second));
    }
    tmp_city_chiken_dist += chiken_dist;
    if(tmp_city_chiken_dist > city_chiken_dist) return;
  }  
  city_chiken_dist = min(tmp_city_chiken_dist,city_chiken_dist);
  return;
}

void select(int start){
  if(selected_store.size() ==  M){
    cal_city_chiken_dist();
    return;
  }

  for(int i = start; i < chiken_stores.size(); i++){
    selected_store.push_back(i);
    select(i+1);
    selected_store.pop_back();
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> town_map[i][j];
      if(town_map[i][j] == 1){
        houses.push_back({i,j});
      }else if(town_map[i][j] == 2){
        chiken_stores.push_back({i,j});
      }
    }
  }

  // cout << "SELECT" << "\n";
  select(0);

  cout << city_chiken_dist;
}