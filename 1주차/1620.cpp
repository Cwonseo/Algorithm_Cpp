#include <bits/stdc++.h>
using namespace std;
int N, M;
map<string, int> mp;
string Q, name, nameArr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 시간 초과 시 작성하면 실행 속도가 높아져 통과 될 수 있음.
    //  iostream과 stdio의 버퍼를 모두 사용하지 않도록 설정
    //
    cin >> N;
    cin >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> name;
        nameArr[i] = name;
        mp.insert({name, i + 1});
    }
    for (int i = 0; i < M; i++)
    {
        cin >> Q;
        if (atoi(Q.c_str()) == 0)
        {
            cout << mp[Q] << "\n";
        }
        else
        {
            cout << nameArr[atoi(Q.c_str()) - 1] << "\n";
        }
    }
}

// - [] 이름:번호

// 배열의 find함수 쓰면 O(n)
// map이용하여 찾을 경우 O(log n)

// MAP 을 사용해야한다.

// atoi(s.c_str()) 사용 시 문자열인지 확인하고 숫자면 숫자로 변경시켜 줌
