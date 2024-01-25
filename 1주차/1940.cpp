#include <bits/stdc++.h>
using namespace std;
int N, M, input[15000], cnt = 0;
map<int, int> mp;
int main()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
        mp[input[i]] += 1;
    }

    for (int i = 0; i < N; i++)
    {
        if (mp[M - input[i]] == 1)
            cnt += 1;
    }
    cout << cnt / 2;
}

// 와 이거 map 쓰면 시간제한에 안걸리는 듯 합니다. O(logn)