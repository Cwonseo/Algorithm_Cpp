#include <bits/stdc++.h>
using namespace std;
int N, M, a[1000], cnt;
vector<int> ret;
void go(int here)
{
    if (ret.size() == M)
    {
        for (int i : ret)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        ret.push_back(i);
        go(i);
        ret.pop_back();
    }
}
int main()
{
    cin >> N >> M;
    go(0);
}
// dfs 완탐 백트래킹 문제

// 완탐으로 선택하고 안하고 풀 때는 끝까지 간 다음에 로직 실행하기.