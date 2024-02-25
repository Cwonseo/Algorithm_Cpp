#include <bits/stdc++.h>
using namespace std;
int N, M, visited[1000];
vector<int> ret;
void dfs(int here, int cnt)
{
    if (cnt == M)
    {
        for (int i : ret)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    for (int i = here; i <= N; i++)
    {
        if (visited[i])
            continue;
        ret.push_back(i);
        visited[i] = 1;
        dfs(i, cnt + 1);
        ret.pop_back();
        visited[i] = 0;
    }
}
int main()
{
    cin >> N >> M;
    dfs(1, 0);
}

// dfs 완탐 문제