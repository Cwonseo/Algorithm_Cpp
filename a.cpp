#include <bits/stdc++.h>
using namespace std;
int N, K, visited[200004], num, minN = 10000000, flag = 0, cnt;
void BFS()
{
    queue<int> q;
    q.push(N);
    visited[N] = 1;
    while (q.size())
    {
        int here = q.front();
        q.pop();
        cout << here << " " << visited[here] << "\n";

        if (here == K && visited[here] - 1 <= minN)
        {
            cout << "도착"
                 << "\n";
            minN = visited[here] - 1;
            cnt += 1;
            flag = 1;
        }

        // if (here > K)
        // {
        //     minN = min(minN, here - K + visited[here]);
        //     continue;
        // }

        if (here + 1 <= 200000)
        {
            if (flag == 0)
                q.push(here + 1);
            if (!visited[here + 1])
                visited[here + 1] = visited[here] + 1;
        }
        if (here - 1 >= 0)
        {
            if (flag == 0)
                q.push(here - 1);
            if (!visited[here - 1])
                visited[here - 1] = visited[here] + 1;
        }

        if (here * 2 <= 200000)
        {
            if (flag == 0)
                q.push(here * 2);
            if (!visited[here * 2])
                visited[here * 2] = visited[here] + 1;
        }
    }
}
int main()
{
    cin >> N >> K;
    if (N > K)
        cout << N - K << "\n"
             << 1;
    else if (N == K)
    {
        cout << 1 << "\n"
             << 1;
    }
    else
    {
        BFS();
        cout << minN << "\n"
             << cnt;
    }
}

// 수빈이가 동생보다 작은경우
// 수빈이가 더 큰 경우 계속 -1
//  즉, K-N초 걸림.
