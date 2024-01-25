#include <bits/stdc++.h>
using namespace std;
int N, K;
int temper[100000], prefixS[100000], sum = 0;
int maxT = 0;
int main()
{
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> temper[i];
    }
    for (int i = 0; i < N; i++)
    {
        sum += temper[i];
        prefixS[i] = sum;
    }

    for (int i = 0; i <= N - K; i++)
    {

        if (i == 0)
        {
            maxT = prefixS[K - 1];
        }
        else if (maxT < prefixS[K + i - 1] - prefixS[i - 1])
        {
            maxT = prefixS[K + i - 1] - prefixS[i - 1];
        }
    }
    cout << maxT;
}