#include <bits/stdc++.h>
using namespace std;

int mp[104][104];
int tmpMp[104][104];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int checked[104][104];
int M, N, cheeseNum, useTime = 0;
int before;
void duplicateMp()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            mp[i][j] = tmpMp[i][j];
        }
    }
}
void DFS(int y, int x)
{
    checked[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx > M || ny > N)
            continue;
        if (mp[ny][nx] == 0 && checked[ny][nx] == 0)
        {
            DFS(ny, nx);
        }
    }
}

int main()
{
    cin >> N >> M;
    fill(&mp[0][0], &mp[103][104], 0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> mp[i][j];
            tmpMp[i][j] = mp[i][j];
            if (mp[i][j] == 1)
                cheeseNum += 1;
        }
    }

    while (cheeseNum > 0)
    {
        before = cheeseNum;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (mp[i][j] == 1)
                {
                    fill(&checked[0][0], &checked[103][104], 0);
                    DFS(i, j);
                    if (checked[0][0] == 1)
                    {
                        tmpMp[i][j] = 0;

                        cheeseNum -= 1;
                    }
                }
            }
        }
        useTime++;

        duplicateMp();
    }
    cout << useTime << "\n"
         << before;
}

// fill 제대로 안해주면 다른 값이 이상해짐..