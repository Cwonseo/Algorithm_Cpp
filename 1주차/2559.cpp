#include <bits/stdc++.h>
using namespace std;
int N, K;
int tmp, psum[100000], sum = 0;
int maxT = -10000004;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }
    for (int i = K; i <= N; i++)
    {
        maxT = max(maxT, psum[i] - psum[i - K]);
    }

    cout << maxT;
}