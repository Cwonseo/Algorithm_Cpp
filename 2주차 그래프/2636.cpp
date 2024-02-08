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
// map을 단계별로 수정하는 경우에는 여분의 맵을 선언해준다.
// 여분의 맵에 단계별 수정사항을 반영하고 여분의 맵을 단계의 끝애서 원래 map에 복사해준다.

// 치즈를 만나면 DFS해서 0,0 포함하면 해당 치즈 없애기.

// 내거는 단계한번에 DFS를 사라질 치즈의 개수만큼 반복해야 함.

// 단계 한번에 BFS한번만 실행해서 1을 만나면 치즈를 녹이는 방식으로 하는 방식이 훨씬 효율적임
// 치즈를 바로 녹이지 않고 자료구조에 넣어뒀다가 한번에 치즈 녹여도 됨.
// 판의 가장자리에 치즈가 없다는 말이 없었다면
// 치즈가 없는 부분을 찾는 로직을 구현했어야 했음.