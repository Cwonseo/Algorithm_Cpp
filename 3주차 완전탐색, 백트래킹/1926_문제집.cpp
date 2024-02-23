#include <bits/stdc++.h>
using namespace std;
int N, M, mp[504][504], visited[504][504], picCnt, ret, cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void dfs(int y, int x)
{
    ret = max(ret, cnt);

    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;

        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (mp[ny][nx] == 0 || visited[ny][nx])
            continue;
        visited[ny][nx] = 1;
        cnt++;
        dfs(ny, nx);
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mp[i][j] == 1 && visited[i][j] == 0)
            {
                cnt = 1;
                visited[i][j] = 1;
                dfs(i, j);
                picCnt++;
            }
        }
    }
    cout << picCnt << "\n"
         << ret;
}