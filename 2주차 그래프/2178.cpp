#include <bits/stdc++.h>
using namespace std;
int N, M;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[104][104];
string line;
int mp[104][104];
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        for (int j = 0; j < M; j++)
        {

            mp[i][j] = int(line[j]) - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    while (q.size())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (visited[ny][nx])
                continue;
            if (!mp[ny][nx])
                continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    cout << visited[N - 1][M - 1];
}

// 맵이 그려져있는 구조이기 때문에 dx, dy를 선언하고 상하좌우를 비교하는 로직을 사용했다.
// 지나야 하는 최소 칸 수( 최단거리 )를 구하는 문제이기 때문에 BFS를 활용하였다.
// 가중치가 모두 1로 동일하기 때문에 BFS만으로 구현할 수 있었다.

// 문법적인 사항
// tie를 이용하여 queue의 맨 앞 부분을 효율적으로 뽑아보았다.
// 모두 붙어서 입력되는 것은 scanf를 사용해보자.