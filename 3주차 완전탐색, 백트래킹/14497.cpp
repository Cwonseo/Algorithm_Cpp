#include <bits/stdc++.h>
using namespace std;

int N, M, x1, yy1, x2, y2, visited[304][304], turn, ok;
char mp[304][304], tmp[304][304];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main()
{
    cin >> N >> M;

    cin >> yy1 >> x1 >> y2 >> x2;
    x1 = x1 - 1;
    yy1 = yy1 - 1;
    x2 = x2 - 1;
    y2 = y2 - 1;

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            tmp[i][j] = mp[i][j];
        }
    }

    while (1)
    {

        queue<pair<int, int>> q;
        q.push({yy1, x1});

        for (int i = 0; i < N; i++)
        {

            for (int j = 0; j < M; j++)
            {
                mp[i][j] = tmp[i][j];
            }
        }
        fill(&visited[0][0], &visited[0][0] + 304 * 304, 0);
        while (q.size())
        {
            int hY = q.front().first;
            int hX = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int nY = dy[j] + hY;
                int nX = dx[j] + hX;
                if (nY < 0 || nX < 0 || nX >= 300 || nY >= 300)
                    continue;
                if (visited[nY][nX])
                    continue;
                if (mp[nY][nX] == '1')
                {
                    tmp[nY][nX] = '0';
                    continue;
                }
                if (mp[nY][nX] == '#')
                {
                    ok = 1;
                    break;
                }
                if (mp[nY][nX] == '0')
                {
                    q.push({nY, nX});
                    visited[nY][nX] = visited[hY][hX] + 1;
                }
            }
            if (ok)
                break;
        }
        if (ok)
            break;
        turn++;
    }
    cout << turn + 1;
}

// BFS통한 덩어리 찾기.
// tmp맵을 만들어 BFS 돌리면서는 tmp맵에 저장하고 BFS 한번 끝날때 마다 원본mp에 tmp맵을 복사시켜줌.
// #을 만나면 한번 더 뛰어야 #을 잡기 때문에 turn+1 출력
