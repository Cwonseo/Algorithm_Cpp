#include <bits/stdc++.h>
using namespace std;
int N, mp[14][14], ret = 100000, visited[14][14];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int cnt, int cost, int i, int j)
{
    // cout << cnt << " " << cost << " " << i << " " << j << "\n";
    if (cnt > 3 || cost > ret)
        return;
    if (cnt == 3)
    {

        ret = min(ret, cost);
    }

    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            int tmpCost = 0;
            if (visited[i][j] || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1])
                continue;
            tmpCost += mp[i][j];
            visited[i][j] = 1;
            for (int k = 0; k < 4; k++)
            {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                tmpCost += mp[ny][nx];
                visited[ny][nx] = 1;
            }
            dfs(cnt + 1, cost + tmpCost, i, j);
            visited[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                visited[ny][nx] = 0;
            }
        }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mp[i][j];
        }
    }

    dfs(0, 0, 0, 0);
    cout << ret;
}