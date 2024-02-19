#include <bits/stdc++.h>
using namespace std;
int N, K, visited[200000], minTry, cnt[200000], tryNum, ret;
long long check = 1;
int main()
{
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    visited[N] += 1;
    cnt[N] += 1;
    while (q.size())
    {
        int here = q.front();

        q.pop();
        for (int next : {here + 1, here - 1, here * 2})
        {
            if (next < 0 || next > 150004)
                continue;
            if (!visited[next])
            {
                q.push(next);
                visited[next] = visited[here] + 1;
                cnt[next] += cnt[here];
            }
            else if (visited[here] + 1 == visited[next])
            {
                cnt[next] += cnt[here];
            }
        }
    }

    cout
        << visited[K] - 1 << "\n"
        << cnt[K];
}

// 나는 BFS로 먼저 최단거리를 구하고
//  다시 BFS를 돌리며 전에 구한 최단거리와 같은 depth에 있는
//  정점들 중 목표값과 같은 것의 개수를 구했지만 이 방식은
//  3의 거듭제곱을 최대 25000번까지 수행해야하기 때문에
//  올바르지 못한 방식이었음.

// BFS 이용하여 최단거리를 구하는 작업과 동시에
// visited와 같은 크기의 cnt배열을 생성하고
// cnt배열에 방문하는 정점마다 이전 정점의 도달 경우의 수에 1을 더해주는 방식으로
// 어떠한 정점까지 올 수 있는 경우의 수를 구해
// 그 경우의 수를 최단거리 방법의 개수로 출력하는 문제였음.

// 틀린 이유
//  결국엔 BFS내에서 경우의수 처리를 하지 못해서 틀림.
// 애초에 경우의 수가 아니라 BFS의 같은 depth에서 처리하려고 해서
// 경우의 수를 생각하지도 못했던 것 같다.

// 반례처리
// 보통 테스트케이스에 모든게 주어지지 않음
// 그렇기 때문에 우리가 직접 테스트케이스를 생각해야 하는 경우가 있음.

// 문제의 최소부분 최대부분을 집중적으로 보자.
// 혹은 같은 경우, 다른 경우에 대해서 생각해보자.

// 제출하면 끝인 코테의 경우엔 테스트케이스를 먼저 생각해보고
// 무제한으로 가능하다면 구현을 먼저 하도록 하자.