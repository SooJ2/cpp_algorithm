#include <iostream>
#include <vector>
#include <string>

using namespace std;

int winner = 0;
int win_time[2]{0,};
int team_time[4] = {0,};
int team_score[2] = {0,};

vector<int> split(string s, string del){
  vector<int> outputs;
  long long pos;
  while((pos = s.find(del)) != string::npos){
    outputs.push_back(stoi(s.substr(0,pos)));
    s.erase(0,pos+del.length());
  }
  if(s.length()){
    outputs.push_back(stoi(s));
  }
  return outputs;
}

void save_time(int type,int team, string time){
  vector<int> int_time;
  int_time = split(time,":");
  if(type == 1){ //save winner time
    win_time[0] = int_time[0];
    win_time[1] = int_time[1];
  }
  else if(type == 2){ //save total time    
    int *hour = &team_time[2*(team-1)];
    int *min = &team_time[2*(team-1)+1];
    *hour += (int_time[0]-win_time[0]);
    *min += (int_time[1]-win_time[1]);
    if(*min >= 60){
      *min -= 60;
      *hour +=1;
    }else if(*min < 0){
      *hour -= 1;
      *min += 60;
    }
  }
}

int main(){
  int goal;
  cin >> goal;
  while(goal){
    int team; string time;
    cin >> team >> time;
    team_score[team-1]++;
    goal--;
    if(winner){
      if(winner == team) continue;
      //winner != team;
      if(team_score[winner-1] > team_score[team-1]) continue;  
      // winner score == team score
      save_time(2,winner,time);
      winner = 0;
    }else{
      //first time
      winner = team;
      save_time(1,winner,time);
    }
  }
  //calculate final
  if(winner){
    save_time(2,winner,"48:00");
  }

  for(int i = 0; i < 4; i++){
    if(team_time[i] == 0) cout << "00";
    else if(team_time[i] < 10) cout << "0" <<team_time[i];
    else cout << team_time[i];
    if(i % 2 == 0) cout << ":";
    else cout << "\n";
  }
}