#include <iostream>
#include <vector>
#include <algorithm>

#define total 5
#define select 3

using namespace std;

int arr[total] = {4, 1, 2, 3, 5};
vector<int> v;

void make_combination(int n, int r, int start,vector<int> vec){
    if (vec.size() == r){ //정해진 수를 모두 선택한 경우
        for (int e:vec){
            cout << e << " ";
        }
        cout << endl;
        return;
    }

    for (int i=start; i < n; i++){
        vec.push_back(v[i]); //숫자 선택하여 벡터에 추가
        make_combination(n,r,i+1,vec);
        vec.pop_back();//다음 경우를 위해 벡터에서 제거
    }
    return;
}
/*
    우리가 머릿속에서 생각하는 조합을 뽑는 과정과 동일
    가장 먼저 첫 자릿수를 고정하고
    다음 자릿수에 그 다음수를 고정
    ...
    위와 같은 과정을 반복하고
    최종적으로 r(뽑을 숫자의 개수)개의 수를 선택한 경우
    r번째 위치에 올 수 있는 이후 숫자가 존재하면,
    r번째에 현재 선택한 숫자를 제거한 후
    다음 숫자를 r번째로 대체
    남은 모든 수를 r번째로 대체하였을 경우
    r-1번째에 존재하던 수를 그 수의 다음수로 대체해 위와 같은 과정을 반복해준다
    단, 해당 자리 이후의 수에는 해당 자리 이후의 위치에 존재하는 수들만이 올 수 있음을 기억해야한다.
*/

int main(){
    // sort(arr, arr+total); //결과물을 오름차순으로 확인하기 위해
    for (int i=0; i<total; i++){
        v.push_back(arr[i]);
    }
    
    vector<int> tmp;
    make_combination(total,select,0,tmp);

}