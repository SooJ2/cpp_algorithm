#include <iostream> //cin, cout, etc.
#include <algorithm> // next_permutation
#include <vector> // vector
#include <set> // set

#define total 5
#define select 3

using namespace std;

int arr[total] = {4, 1, 2, 3, 5};

vector<int> v;

void make_permutation(int n, int r, int depth)
{
    if (depth == r)
    {
        for (int i = 0; i < r; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(arr[i], arr[depth]);
        make_permutation(n, r, depth + 1);
        swap(arr[i], arr[depth]);
    }
    return;
}

void make_permutation(int n, int r, int depth, vector<vector<int>> *result) //함수 overloading
{
    if (depth == r)
    {                                              // depth가 select하기 원하는 수 다음 index를 가질 때, >> depth가 r-1까지를 기저 조건으로 잡게되면, v[r-1]의 element swap이 일어나지 않는다.
        vector<int> tmp(v.begin(), v.begin() + r); // select할 index까지의 수열을 새로운 vector에 담아
        (*result).push_back(tmp);                  // *result vector에 넣어주기
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(v[depth], v[i]); // depth번째 element에 각 각 다른 수가 들어오는 경우를 본다
        make_permutation(n, r, depth + 1, result);
        swap(v[depth], v[i]); // i번째 element가 depth 위치에 있을 경우의 순열을 모두 계산해 주었으니 다시 위치를 바꾸어준다.
        // 만일 위치 변경이 이뤄지지 않을 경우, 특정 순열이 중복되고, 빠지는 경우가 생기게 된다. 새로운 재귀 함수를 call하는 입장에서, 이후 숫자들간의 위치를 고정했다는 가정하에 코드가 작성되었기 때문
    }
}

int main()
{
    // initialize vector
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        v.push_back(arr[i]);
    sort(v.begin(), v.end());

    /* 학습 내용 복습해보기 - 단순히 따라 구현*/

    // using next_permutation (vector example)
    cout << "vector example" << endl;
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));

    // using next_permutation (array example)
    sort(arr, arr + total);

    cout << "array example" << endl;
    do
    {
        for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        {
            cout << arr[i];
        }
        cout << endl;

    } while (next_permutation(arr, arr + total));

    // recursive function example
    cout << "recursion function example" << endl;
    make_permutation(sizeof(arr) / sizeof(*arr), sizeof(arr) / sizeof(*arr), 0);
    return 0;


    /* 참고 없이 구현해보기 */

    // next_permutation 함수 사용
    /* 위 방법들은 n-1 <= r일 경우, 중복된 순열이 나오는 경우가 있음.
    따라서, next_permutation의 결과 값을 set에 저장해 중복된 vector 순열 저장을 피하도록 구현*/
    set<vector<int>> s;
    do
    {
        vector<int> tmp(v.begin(), v.begin() + select + 1);
        s.insert(tmp);

    } while (next_permutation(v.begin(), v.end()));

    for (vector<int> vec : s)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    // recursive function 사용
    vector<vector<int>> output;
    make_permutation(total, select, 0, &output);

    cout << "output" << endl;
    for (vector<int> vec : output)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}