#include <bits/stdc++.h>
using namespace std;
int N, M;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int mp[8][8];
int wallMp[8][8];
int checked[8][8];
int cnt, wallcnt;
int result = 100;
void DFS(int y, int x)
{
    cnt++;
    checked[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (wallMp[ny][nx] == 0 && checked[ny][nx] != 1)
        {
            DFS(ny, nx);
        }
    }
}
void duplicateMp()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            checked[i][j] = 0;
            wallMp[i][j] = mp[i][j];
        }
    }
}

void getArea()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (wallMp[i][j] == 2 && checked[i][j] != 1)
            {
                DFS(i, j);
            }
        }
    }
}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 1)
                wallcnt += 1;
        }
    }

    for (int y1 = 0; y1 < N; y1++)
    {
        for (int x1 = 0; x1 < M; x1++)
        {
            for (int y2 = 0; y2 < N; y2++)
            {
                for (int x2 = 0; x2 < M; x2++)
                {
                    for (int y3 = 0; y3 < N; y3++)
                    {
                        for (int x3 = 0; x3 < M; x3++)
                        {
                            duplicateMp();
                            if (mp[y1][x1] == 0 && mp[y2][x2] == 0 && mp[y3][x3] == 0)
                            {
                                wallMp[y1][x1] = 1;
                                wallMp[y2][x2] = 1;
                                wallMp[y3][x3] = 1;
                                cnt = 0;
                                getArea();
                                result = min(cnt, result);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << N * M - (wallcnt + 3 + result);
}

// 입력을 받을 때 pair로 벽을 세울 수 있는 i와 j를 미리 받아두면 조합을 얻을 수 있음.
//  이 조합을 기반으로 for문을 돌리면서 벽을 세우는 경우를 고려한다면 세울 수 있는 영역을 3개 고르는 것이므로
//  3번만 for문을 돌려도 됨.

// 하지만 나의 경우에는 세 영역의 y, x값을 모두 구하는 방식으로 로직을 짰기 때문에 for문 중첩이 엄청나게 되는 것을 볼 수 있음.

// 그리고 나는 벽을 세운 mp을 따로 만들어서 했는데 그렇게 하지 않고
//  맵에 벽을 세우고 바이러스 영역의 넓이를 구한 뒤에 세운 벽을 없애는 형식으로 해도 될 것같음.

// 배열 초기화해주기 for문을 돌리지 않고 fill을 사용하면 한줄로 끝낼 수 있음.
// 어떤 경우의 수를 기반으로 한다고 하면 보통 경우의 수마다 초기화해주는걸 잘 봐야 함.