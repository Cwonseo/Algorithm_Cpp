#include <bits/stdc++.h>
using namespace std;
int N, M;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int visited[54][54];
char mp[54][54];
int maxDist = 0;

vector<pair<int, int>> land;
void BFS(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    while (q.size())
    {
        int hereY = q.front().first;
        int hereX = q.front().second;
        maxDist = max(maxDist, visited[hereY][hereX] - 1);
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + hereY;
            int nx = dx[i] + hereX;
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (visited[ny][nx] > 0)
                continue;
            if (mp[ny][nx] == 'L')
            {
                q.push({ny, nx});
                visited[ny][nx] = visited[hereY][hereX] + 1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];

            if (mp[i][j] == 'L')
            {
                land.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < land.size(); i++)
    {
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        BFS(land[i].first, land[i].second);
    }
    cout << maxDist;
}

// 1. 최단거리 구하기.
// 2. 최단거리에서 가장 긴 시간이 걸리는 육지 두 곳 구하기.

// 1. 육지들 중 두 곳을 선택한다.
// 2. 두 곳의 최단거리를 구한다.
//    - 구할때 마다 최단거리의 최대값을 비교한다.

// 시간초과
// 조합을 쓰고 BFS를 쓰는게 아니라
// 그냥 BFS만 써서도 풀 수가 있음.
// BFS를 쓰면 visited배열에 모든 시작점으로부터 모든 L까지의 거리가 저장되기 때문에
// 그 중에서 가장 큰 것을 비교하여 가장 큰 최단거리를 구하면 되는거임.