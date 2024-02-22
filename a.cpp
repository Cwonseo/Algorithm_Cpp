#include <bits/stdc++.h>
using namespace std;
int N, K, prevN, ok = 0, visited[2][500004], turn, flag;

int main()
{
    cin >> N >> K;
    if (N == K)
    {
        cout << 0;
        return 0;
    }
    queue<int> q;
    q.push(N);
    visited[0][N] += 1;

    while (q.size())
    {
        K += turn;
        if (visited[turn % 2][K])
        {
            ok = 1;
            break;
        }
        int qSize = q.size();

        for (int i = 0; i < qSize; i++)
        {
            int here = q.front();

            if (K > 500000)
            {
                flag = 1;
                break;
            }
            if (here == K)
            {
                ok = 1;
                break;
            }
            q.pop();
            for (int next : {here + 1, here - 1, here * 2})
            {
                if (next < 0 || next > 500000)
                {
                    continue;
                }
                if (visited[(turn + 1) % 2][next])
                    continue;
                q.push(next);
                visited[(turn + 1) % 2][next] = visited[turn % 2][here] + 1;
            }
        }
        if (flag)
            break;
        if (ok)
            break;
        turn += 1;
    }
    if (ok)
        cout << turn;
    if (flag)
        cout << -1;
}

// turn을 분리하고 싶을 때 사용하는 ㅓㅅ?

// 플루드필 알고리즘

// q.size()를 사용해서
//  현재 turn만큼 반복문을 돌려서 push를 시키는 작업.
//  그렇게 하면 이 문제의 경우 1-> 3 -> 9 ....
//  와 같이 턴마다 실행되는 것을 알 수 있다.

// 수빈이가 먼저 왔을 때 홀짝이 맞는 경우
// 이게 무슨 소리지
