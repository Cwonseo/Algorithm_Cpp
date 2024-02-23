#include <bits/stdc++.h>
using namespace std;
int N, M, H, a, b;
int visited[34][34];
int ret = 10000;
bool checkOk()
{
    for (int i = 1; i <= N; i++)
    {
        int check = i;
        for (int j = 1; j <= H; j++)
        {
            if (visited[j][check] == 1)
                check += 1;
            else if (visited[j][check - 1] == 1)
                check -= 1;
        }
        if (check != i)
            return 0;
    }
    return 1;
}
void dfs(int y, int x, int cnt)
{
    if (cnt > 3 || cnt >= ret)
        return;

    if (checkOk())
    {
        ret = min(ret, cnt);
    }

    for (int i = y; i <= H; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1])
                continue;
            visited[i][j] = 1;
            dfs(i, j, cnt + 1);
            visited[i][j] = 0;
        }
    }
}
int main()
{
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        visited[a][b] = 1;
    }
    dfs(1, 1, 0);
    if (ret > 3)
        cout << -1;
    else
        cout << ret;
}