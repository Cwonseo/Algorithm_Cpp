#include <bits/stdc++.h>
using namespace std;
int N, M, visited[500];
vector<int> ret;
void dfs(int cnt)
{

    if (cnt == M)
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
        if (visited[i])
            continue;
        ret.push_back(i);
        visited[i] = 1;
        dfs(cnt + 1);
        ret.pop_back();
        visited[i] = 0;
    }
}
int main()
{
    cin >> N >> M;
    dfs(0);
}

// 완전탐색 하는 문제임.
// 완전탐색 하면서 M 개수 기준으로 가지치기 하는 백트래킹 문제
// 백트래킹 문제에는 대부분 재귀 호출 전후로 값을 초기화시켜준다는 특성이 있음.