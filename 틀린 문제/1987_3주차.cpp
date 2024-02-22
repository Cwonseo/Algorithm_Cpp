#include <bits/stdc++.h>
using namespace std;
int R, C, maxV, flag;
char mp[24][24];
int visited[24][24];
int checkA[28];
string checkSt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void DFS(int y, int x)
{
    if (flag)
        return;
    // cout << y << x << " " << mp[y][x] << " " << visited[y][x] << "\n";
    maxV = max(maxV, visited[y][x]);
    if (maxV == checkSt.size())
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if (ny < 0 || nx < 0 || ny >= R || nx >= C)
            continue;

        if (checkA[mp[ny][nx] - 'A'] == 1)
        {
            continue;
        }
        checkA[mp[ny][nx] - 'A'] = 1;
        visited[ny][nx] = visited[y][x] + 1;
        DFS(ny, nx);
        visited[ny][nx] = 0;
        checkA[mp[ny][nx] - 'A'] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> mp[i][j];

            if (checkSt.find(mp[i][j]) == string::npos)
            {
                checkSt += mp[i][j];
            }
        }
    }
    checkA[mp[0][0] - 'A'] = 1;

    visited[0][0] = 1;
    DFS(0, 0);

    cout << maxV;
}

// 이동 시 3개나 2개의 방향으로 이동할 수 있는데 알파벳은 26개까지 있으므로
// 3^26까지 시간이 걸릴 수 있음.

// 시간초과 문제.

// 처음에는 지금까지 방문한 곳을 문자열로 만들어서 visitedString[][]로 각 자리마다 방문한 순서를 저장하려고 했음.
// 근데 이렇게 하면 추가하려는 값이 원래 문자열에 존재하는지 검색을 하는 시간이 너무 많아져서 복잡도가 높아짐.

// 그래서 알파벳을 int로 표현하기 위해 아스키코드를 활용하여 1차원배열에 방문한 알파벳의 아스키코드는 1로 작성하기로 함
//  DFS를 돌다가 만약 넣을 수 없고 이전으로 돌아가는 경우를 위해 DFS가 끝나면 끝난 인덱스의 아스키코드 배열과 visited 배열을 0으로 바꾸어줌