#include <bits/stdc++.h>
using namespace std;
int N, cnt;
int a[104], visited[104], maxN;
bool checkS(int sum)
{
    for (int i = 2; i < sum; i++)
    {
        if (sum % i == 0)
            return false;
    }
    return true;
}
void go(int sum, int here)
{

    if (here == N)
    {
        maxN = max(sum % 11, maxN);
        return;
    }
    go(sum + a[here], here + 1);
    go(sum, here + 1);
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    go(0, 0);
    cout << cnt;
}