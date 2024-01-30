#include <bits/stdc++.h>
using namespace std;
int N, M, J, K;
int res = 0, start = 0;
int main()
{
    cin >> N >> M;
    cin >> J;
    int end = M;
    for (int i = 0; i < J; i++)
    {
        cin >> K;
        if (start < K && K <= end)
        {
            continue;
        }
        else if (K <= start)
        {
            while (K != start + 1)
            {
                start -= 1;
                end -= 1;
                res += 1;
            }
        }
        else if (K > end)
        {
            while (K != end)
            {
                start += 1;
                end += 1;
                res += 1;
            }
        }
    }
    cout << res;
}

// 그냥 구현 문제였던 듯