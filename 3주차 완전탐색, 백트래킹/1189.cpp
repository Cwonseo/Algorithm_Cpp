#include <bits/stdc++.h>
using namespace std;
int R, C, K, visited[10][10];
char mp[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret[100];
void dfs(int y, int x)
{
    if (y == 0 && x == C - 1)
    {
        ret[visited[y][x]] += 1;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;
        if (visited[ny][nx] || mp[ny][nx] == 'T')
            continue;

        visited[ny][nx] = visited[y][x] + 1;
        dfs(ny, nx);
        visited[ny][nx] = 0;
    }
}
int main()
{
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> mp[i][j];
        }
    }
    visited[R - 1][0] = 1;
    dfs(R - 1, 0);
    cout << ret[K];
}

// 경로 완전탐색 문제

// 모든 경로를 찾는 문제의 경우에는 dfs를 사용한 뒤에 visited를 원래대로 복구 시켜주는게 핵심!