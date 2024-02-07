#include <bits/stdc++.h>
using namespace std;
int N, M;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int mp[8][8];
int wallMp[8][8];
int checked[8][8];
int cnt, wallcnt;
int result = 100;
void DFS(int y, int x)
{
    cnt++;
    checked[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (wallMp[ny][nx] == 0 && checked[ny][nx] != 1)
        {
            DFS(ny, nx);
        }
    }
}
void duplicateMp()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            checked[i][j] = 0;
            wallMp[i][j] = mp[i][j];
        }
    }
}

void getArea()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (wallMp[i][j] == 2 && checked[i][j] != 1)
            {
                DFS(i, j);
            }
        }
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
            if (mp[i][j] == 1)
                wallcnt += 1;
        }
    }

    for (int y1 = 0; y1 < N; y1++)
    {
        for (int x1 = 0; x1 < M; x1++)
        {
            for (int y2 = 0; y2 < N; y2++)
            {
                for (int x2 = 0; x2 < M; x2++)
                {
                    for (int y3 = 0; y3 < N; y3++)
                    {
                        for (int x3 = 0; x3 < M; x3++)
                        {
                            duplicateMp();
                            if (mp[y1][x1] == 0 && mp[y2][x2] == 0 && mp[y3][x3] == 0)
                            {
                                wallMp[y1][x1] = 1;
                                wallMp[y2][x2] = 1;
                                wallMp[y3][x3] = 1;
                                cnt = 0;
                                getArea();
                                result = min(cnt, result);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << N * M - (wallcnt + 3 + result);
}