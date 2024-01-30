#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int mp[101][101], visited[101][101];
int M, N, K, ry, rx, lx, ly;
int totalRes = 0, res = 0;
vector<int> resArr;
void dfs(int y, int x)
{
    visited[y][x] = 1;
    res += 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (visited[ny][nx])
            continue;
        if (!mp[ny][nx])
            continue;

        dfs(ny, nx);
    }
}
int main()
{
    cin >> M >> N >> K;
    fill(&mp[0][0], &mp[0][0] + 101 * 101, 1);
    for (int i = 0; i < K; i++)
    {
        cin >> lx >> ly >> rx >> ry;
        for (int j = ly; j < ry; j++)
        {
            for (int k = lx; k < rx; k++)
            {
                mp[j][k] = 0;
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && mp[i][j])
            {
                dfs(i, j);
                totalRes += 1;
                resArr.push_back(res);
                res = 0;
            }
        }
    }
    cout << totalRes << "\n";
    sort(resArr.begin(), resArr.end());
    for (int i : resArr)
    {
        cout << i << " ";
    }
}

// 로직은 다 짜놓고 처음 맵 선언하는거에서 헤맴.
// 좌표를 찍어서 칸마다 0을 지정해주는 부분에서 헤매다가 1씩 줄여서 mp 배열에 넣어주니 성공.

// 로직 설명
// 직사각형의 꼭지점을 받아서 해당하는 영역을 mp에 0 으로 지정함.
// 그 후 dfs를 이용하여 connected components의 개수를 구했음.
// 각각 넓이도 알아야 했기에 visited 생성될 때마다 cnt++ 해줬음.