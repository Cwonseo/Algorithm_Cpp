#include <bits/stdc++.h>
using namespace std;
int tc, n, cnt;
int main()
{

    while (scanf("%d", &n) != EOF)
    {
        int one = 1;
        int cnt = 1;
        while (1)
        {
            if (one % n == 0)
            {
                cout << cnt << "\n";
                break;
            }
            else
            {
                one = (one * 10 + 1) % n;
                cnt++;
            }
        }
    }
}

//(A+B)%n == A%n + B%n