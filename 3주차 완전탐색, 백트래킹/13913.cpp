#include <bits/stdc++.h>
using namespace std;
int N, K, visited[200000], prevN[200000], ret[200000];
int main()
{
    cin >> N >> K;
    queue<int> q;

    q.push(N);
    visited[N] += 1;
    prevN[N] = -1;
    while (q.size())
    {
        int here = q.front();
        q.pop();
        if (here == K)
            break;
        for (int next : {here + 1, here - 1, here * 2})
        {
            if (next < 0 || next > 150000)
                continue;
            if (visited[next])
                continue;
            q.push(next);
            visited[next] = visited[here] + 1;
            prevN[next] = here;
        }
    }
    cout << visited[K] - 1 << "\n";
    int here = K;
    for (int i = visited[K] - 1; i >= 0; i--)
    {
        ret[i] = prevN[here];
        here = prevN[here];
    }
    for (int i = 1; i <= visited[K] - 1; i++)
    {
        cout << ret[i] << " ";
    }
    cout << K;
}

// BFS 돌면서 prev 배열에 해당 노드의 이전 노드를 저장하여 trace한다.
