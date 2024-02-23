#include <bits/stdc++.h>
using namespace std;
int L, N, M;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dz[] = {-1, 1};
struct pos
{
    int z, y, x;
};
int main()
{

    while (1)
    {
        queue<pos> q;
        int flag = 0;
        char mp[34][34][34];
        int visited[34][34][34];
        cin >> L >> N >> M;
        if (L == 0 && N == 0 && M == 0)
            break;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < M; k++)
                {
                    visited[i][j][k] = 0;
                    cin >> mp[i][j][k];
                    if (mp[i][j][k] == 'S')
                    {
                        visited[i][j][k] = 1;
                        q.push({i, j, k});
                    }
                }
            }
        }

        while (q.size())
        {
            int hz = q.front().z;
            int hy = q.front().y;
            int hx = q.front().x;
            if (mp[hz][hy][hx] == 'E')
            {
                cout << "Escaped in " << visited[hz][hy][hx] - 1 << " minute(s).\n";
                flag = 1;
                break;
            }
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = dy[i] + hy;
                int nx = dx[i] + hx;

                if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                    continue;
                if (visited[hz][ny][nx] || mp[hz][ny][nx] == '#')
                    continue;
                visited[hz][ny][nx] = visited[hz][hy][hx] + 1;
                q.push({hz, ny, nx});
            }

            for (int i = 0; i < 2; i++)
            {
                int nz = dz[i] + hz;
                if (nz < 0 || nz >= L)
                    continue;
                if (visited[nz][hy][hx] || mp[nz][hy][hx] == '#')
                    continue;
                visited[nz][hy][hx] = visited[hz][hy][hx] + 1;
                q.push({nz, hy, hx});
            }
        }
        if (!flag)
        {
            cout << "Trapped!\n";
        }
    }
}

// struct 설정을 잘못해준거로 약 30분 헤맸음.
// 3차원 BFS 문제