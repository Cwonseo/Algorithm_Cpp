#include <bits/stdc++.h>
using namespace std;
int N, input;
int visited[100][100][100];
vector<int> scv;
int attack[6][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 3, 1},
    {9, 1, 3},
};
struct scvs
{
    int a, b, c;
};
void BFS(vector<int> scv)
{
    queue<scvs> q;
    q.push({scv[0], scv[1], scv[2]});
    visited[scv[0]][scv[1]][scv[2]] = 1;
    int flag = 0;
    while (q.size())
    {
        int hereA = q.front().a;
        int hereB = q.front().b;
        int hereC = q.front().c;

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int na = max(0, hereA - attack[i][0]);
            int nb = max(0, hereB - attack[i][1]);
            int nc = max(0, hereC - attack[i][2]);

            if (na == 0 && nb == 0 && nc == 0)
            {
                cout << visited[hereA][hereB][hereC];
                flag = 1;
                break;
            }

            if (visited[na][nb][nc] > 0)
                continue;
            visited[na][nb][nc] = visited[hereA][hereB][hereC] + 1;
            q.push({na, nb, nc});
        }
        if (flag == 1)
            break;
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        scv.push_back(input);
    }

    BFS(scv);
}

// 순열문제
// 인줄 알았는데 최단거리 구하는 BFS

// 맵 BFS를 그래프나 집합과 같은 것으로 나타낼 수 있어야 함.

// 최단거리를 구하는거로 생각하면 되는 듯

// 그래프 형식으로 한 상태로 BFS를 하는 것으로 생각하면 됨.
// 1개 -> 6개 -> 각각 6개씩 늘어나는 형식으로.