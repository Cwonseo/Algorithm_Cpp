#include <bits/stdc++.h>
using namespace std;
int N, L, R, ret = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int mp[54][54], visited[54][54];
vector<pair<int, int>> BFS(int y, int x)
{
    vector<pair<int, int>> unionEle;
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    unionEle.push_back({y, x});

    while (q.size())
    {
        int hereY = q.front().first;
        int hereX = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + hereY;
            int nx = dx[i] + hereX;
            if (ny < 0 || nx < 0 || ny >= N || nx >= N)
                continue;
            if (visited[ny][nx])
                continue;
            if (L <= abs(mp[ny][nx] - mp[hereY][hereX]) && abs(mp[ny][nx] - mp[hereY][hereX]) <= R)
            {
                q.push({ny, nx});
                visited[ny][nx] = 1;
                unionEle.push_back({ny, nx});
            }
        }
    }

    return unionEle;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mp[i][j];
        }
    }

    while (1)
    {

        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        vector<pair<int, int>> unionArr[1254];

        int cnt = 0, flag = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0)
                {
                    vector<pair<int, int>> unionEle;
                    unionEle = BFS(i, j);

                    if (unionEle.size() > 1)
                    {
                        flag = 1;
                        unionArr[cnt] = unionEle;
                        cnt++;
                    }
                }
            }
        }

        if (flag == 0)
            break;
        for (vector<pair<int, int>> unions : unionArr)
        {

            if (unions.size() == 0)
                continue;

            int sum = 0;
            for (int i = 0; i < unions.size(); i++)
            {
                sum += mp[unions[i].first][unions[i].second];
            }
            int divided = sum / unions.size();
            for (int i = 0; i < unions.size(); i++)
            {
                mp[unions[i].first][unions[i].second] = divided;
            }
        }
        cout << "\n";
        ret += 1;
    }
    cout << ret;
}

// 처음부터 제대로 설계해서 맞춘 문제
//  먼저 맵 형태로 나와있어서 BFS를 이용해야겠다고 생각했음.
//  1. BFS
//  BFS를 통해 돌면서 두 나라의 인구 차이가 주어진 범위에 알맞다면 계속해서 탐색 진행하도록 했음.
//  그리고 알맞은 국가는 연합 vector에 넣어 해당 vector를 BFS종료 시 반환하도록 했음.

// 2. 인구 재설정
//  BFS통해 얻은 연합을 반복문을 통해 돌면서 연합마다 인구를 동일하게 맞춰줬음.
//  그렇게 인구가 변한 mp을 재할당 시켜줌.

// 1번과 2번을 계속해서 반복하다가 BFS결과에서 연합이 나오지 않는 경우 break하도록 했음.