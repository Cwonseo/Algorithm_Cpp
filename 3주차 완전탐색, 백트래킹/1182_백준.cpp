#include <bits/stdc++.h>
using namespace std;
int N, M, visited[1000], a[1000], cnt;

void go(int sum, int here)
{
    if (here >= N)
    {
        if (sum == M)
        {

            cnt += 1;
        }
        return;
    }

    go(sum + a[here], here + 1);

    go(sum, here + 1);
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    go(0, 0);

    if (M == 0)
        cnt -= 1;
    cout << cnt;
}

// dfs 완탐 백트래킹 문제

// 완탐일 때 해당 인덱스 O, X해서 풀 때는 끝까지 간 다음에 로직 실행하기.
