#include <iostream>
// #include <vector>
#include <algorithm>

using namespace std;

int N, trial;
int SCVs[3], attack[3] = {9, 3, 1};
// vector<int> hp;

bool comp(int a, int b){
  return a > b;
}

int under_attack_SCVs(int t,int arr[3]){
  int new_SCVs[3];
  copy(arr,arr+3,new_SCVs);

  cout << "UNDER"<<" ";

  for(int i = 0; i < 3; i++){
    new_SCVs[i] -= attack[i];
    // arr[i] -= attack[i];
  }

  for(int i = 0; i < 3; i++){
    cout << new_SCVs[i]<<" ";
  }cout << "\n";



  int first = 0,second = 0;
  // if(min_element(new_SCVs,new_SCVs+3) <= 0){
  cout<<"MAX" <<*min_element(new_SCVs, new_SCVs+3) <<"\n" ;
  // if(*min_element(arr, arr+3) <= 0){
  if(*max_element(new_SCVs, new_SCVs+3) <= 0){
    cout << "RETURN: " << t << "\n";
    return t;
  }else{
    sort(new_SCVs,new_SCVs+3,comp);
    cout << "[FIRST]"<<"\n";
    first = under_attack_SCVs(t+1,new_SCVs);
    swap(new_SCVs[1],new_SCVs[2]);
    cout << "[SECOND]"<<"\n";
    second = under_attack_SCVs(t+1,new_SCVs);

    // sort(arr,arr+3,comp);
    // cout << "[FIRST]"<<"\n";
    // first = under_attack_SCVs(t+1,arr);
    // swap(arr[1],arr[2]);
    // cout << "[SECOND]"<<"\n";
    // second = under_attack_SCVs(t+1,arr);
  }
  cout << "*COMP RET: " << first << " " << second << "\n\n";
  return first < second ? first : second;
}

int attack_SCVs(){
  sort(SCVs, SCVs+3,comp);
  cout << "check ";
  for(int i = 0; i < 3; i++){
      cout << SCVs[i]<<" ";
  }cout << "\n";
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
    for(int i = 0; i < 3; i++){
      cout << SCVs[i]<<" ";
    }cout << "\n";
    
  }
  return -1;
}

int main(){
  cin >> N;
  // int input;
  for(int i = 0; i < N; i++){
    cin >> SCVs[i]; 
    // cin >> input;
    // hp.push_back(input);
    // push_heap(hp.begin(),hp.end())
  }
  
  int answer = -1;
  while(answer == -1){
    answer = attack_SCVs();
  }
  cout << trial + answer << "\n";
}

/*
3
54 18 6
*/