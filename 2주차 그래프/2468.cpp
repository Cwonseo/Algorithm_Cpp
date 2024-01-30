#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int visited[104][104], mp[104][104];
int N, res = 0;

void dfs(int y, int x, int height)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if (visited[ny][nx])
            continue;
        if (mp[ny][nx] <= height)
            continue;

        dfs(ny, nx, height);
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
    for (int k = 0; k <= 100; k++)
    {
        int active = 0;
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mp[i][j] > k && visited[i][j] == 0)
                {
                    dfs(i, j, k);
                    active += 1;
                }
            }
        }
        res = max(res, active);
    }
    cout << res << "\n";
    return 0;
}

// 틀림.. 답은 나오는데 반례를 찾지 못함.

// 맞왜틀. 반례를 생각해보자.

//  최소 최대 : 예를들어 1에서 10이면  1과 10의 경우에도 체크를 해보자.
//  없거나 있거나 : 없어도 된다 혹은 있어야한다.

// 반례를 못찾은게 아니라 fill() 사용법 미숙
//  fill()을 통해 초기화 할때 배열 전체의 범위로 지정해야한다.