#include <bits/stdc++.h>
using namespace std;
int N, bits[65][65];
// 재귀함수는 return의 위치 굉장히 중요함.
void divide(int x, int y, int n)
{
    if (n == 1)
    {
        cout << bits[x][y];
        return;
    }
    int res = bits[x][y];

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (bits[i][j] != res)
            {
                cout << "(";
                divide(x, y, n / 2);
                divide(x, y + n / 2, n / 2);
                divide(x + n / 2, y, n / 2);
                divide(x + n / 2, y + n / 2, n / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << res;
    return;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &bits[i][j]);
        }
    }
    divide(0, 0, N);
}

// 재귀함수. 같은 로직이 매개변수가 변하며 반복되는 경우 사용.