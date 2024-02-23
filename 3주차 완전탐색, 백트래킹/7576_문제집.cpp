#include <bits/stdc++.h>
using namespace std;
int N, M, mp[1004][1004], visited[1004][1004], maxV, flag;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> apples;
int main()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 1)
            {
                apples.push_back({i, j});
            }
        }
    }
    queue<pair<int, int>> q;
    for (pair<int, int> apple : apples)
    {
        q.push({apple.first, apple.second});
        visited[apple.first][apple.second] = 1;
    }
    while (q.size())
    {
        int hy = q.front().first;
        int hx = q.front().second;
        maxV = max(maxV, visited[hy][hx] - 1);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + hy;
            int nx = dx[i] + hx;
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (visited[ny][nx] || mp[ny][nx] == -1)
                continue;
            visited[ny][nx] = visited[hy][hx] + 1;
            mp[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mp[i][j] == 0)
            {
                flag = 1;
            }
        }
    }
    if (flag)
        cout << -1;
    else
        cout << maxV;
}

// BFS문제