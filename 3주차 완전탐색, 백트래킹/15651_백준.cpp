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

// dfs 이용 완탐.
// ret의 사이즈에 따라 백트래킹