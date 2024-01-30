#include <bits/stdc++.h>
using namespace std;
// 풀기 전 connected component를 세는 문제이므로 DFS 활용하여 visited로 문제 풀기.
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int mp[54][54];
int visited[54][54];
int M, N, K, y, x, tc;

void DFS(int y, int x)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || ny < 0 || nx >= M || ny >= N || mp[ny][nx] == 0)
            continue;
        if (visited[ny][nx])
            continue;
        DFS(ny, nx);
    }
}

int main()
{
    cin >> tc;
    vector<int> result;
    for (int j = 0; j < tc; j++)
    {
        cin >> M >> N >> K;
        int num = 0;
        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < M; k++)
            {
                mp[i][k] = 0;
                visited[i][k] = 0;
            }
        }

        for (int i = 0; i < K; i++)
        {
            cin >> x >> y;
            mp[y][x] = 1;
        }

        for (int i = 0; i < N; i++)
        {
            for (int k = 0; k < M; k++)
            {
                if (visited[i][k] == 0 && mp[i][k])
                {
                    DFS(i, k);
                    num += 1;
                }
            }
        }
        result.push_back(num);
    }
    for (int i : result)
    {
        cout << i << "\n";
    }
}

// 문법사항
// fill(배열 처음 주소, 매열 마지막 주소,0)을 이용해 0으로 채우기