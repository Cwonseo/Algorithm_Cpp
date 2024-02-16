#include <bits/stdc++.h>
using namespace std;
int R, C, visitedF[1004][1004], visitedJ[1004][1004];
char mp[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
pair<int, int> jPos;
vector<pair<int, int>> fPos;

void BFS(pair<int, int> jPos, vector<pair<int, int>> fPos)
{
    queue<pair<int, int>> jq;
    queue<pair<int, int>> fq;
    jq.push({jPos.first, jPos.second});
    visitedJ[jPos.first][jPos.second] = 1;
    for (pair<int, int> fire : fPos)
    {
        fq.push({fire.first, fire.second});
        visitedF[fire.first][fire.second] = 1;
    }
    while (fq.size())
    {
        int hy = fq.front().first;
        int hx = fq.front().second;
        fq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + hy;
            int nx = dx[i] + hx;
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue;
            if (visitedF[ny][nx])
                continue;
            if (mp[ny][nx] == '.')
            {
                fq.push({ny, nx});
                visitedF[ny][nx] = visitedF[hy][hx] + 1;
            }
        }
    }
    while (jq.size())
    {
        int hy = jq.front().first;
        int hx = jq.front().second;
        if (hy == 0 || hy == R - 1 || hx == 0 || hx == C - 1)
        {
            cout << visitedJ[hy][hx];
            return;
        }
        jq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + hy;
            int nx = dx[i] + hx;
            if (ny < 0 || nx < 0 || ny >= R || nx >= C)
                continue;
            if (visitedJ[ny][nx])
                continue;
            if (mp[ny][nx] == '.')
            {
                visitedJ[ny][nx] = visitedJ[hy][hx] + 1;
                if (visitedJ[ny][nx] < visitedF[ny][nx] || visitedF[ny][nx] == 0)
                    jq.push({ny, nx});
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int flag = 0;
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'J')
            {
                flag = 1;
                jPos = {i, j};
            }
            if (mp[i][j] == 'F')
            {
                fPos.push_back({i, j});
            }
        }
    }
    if (flag == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        BFS(jPos, fPos);
    }
}

// 흠,, 너무 더럽게 푼듯한 느낌
//  처음 설계했을 때랑 너무 달라졌음.

// 1. 불이 퍼져나가는 시간을 계산하여 visitedF에 시간별 불 전파정도를 나타냄
// 2. J로부터 탐색을 하며 불이 전파되기 이전에 J가 이동한 경우에만 이동할 수 있도록 함.
// 3. 만약 J가 끄트머리에 닿았다면 출력하고 끝내기