#include <iostream>
#include <algorithm>

using namespace std;

int N, trial;
int SCVs[3], attack[3] = {9, 3, 1};

bool comp(int a, int b){
  return a > b;
}

int under_attack_SCVs(int t,int arr[3]){
  int new_SCVs[3];
  copy(arr,arr+3,new_SCVs);

  for(int i = 0; i < 3; i++){
    new_SCVs[i] -= attack[i];
  }
  int first = 0,second = 0;

  if(*max_element(new_SCVs, new_SCVs+3) <= 0){
    return t;
  }else{
    sort(new_SCVs,new_SCVs+3,comp);
    first = under_attack_SCVs(t+1,new_SCVs);
    swap(new_SCVs[1],new_SCVs[2]);
    second = under_attack_SCVs(t+1,new_SCVs);
  }
  return first < second ? first : second;
}

int attack_SCVs(){
  sort(SCVs, SCVs+3,comp);

  if(SCVs[2] < 12){
    int first, second;
    first = under_attack_SCVs(1, SCVs);
    swap(SCVs[1],SCVs[2]);
    second = under_attack_SCVs(1, SCVs);
    return first < second ? first : second;
  }else{
    for(int i = 0; i < 3; i++){
      SCVs[i] -= attack[i];
    }
    trial += 1;
  }
  return -1;
}

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> SCVs[i]; 
  }
  
  int answer = -1;
  while(answer == -1){
    answer = attack_SCVs();
  }
  cout << trial + answer << "\n";
} //0ms

/*
3
54 18 6
*/