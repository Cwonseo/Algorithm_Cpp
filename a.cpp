#include <bits/stdc++.h>
using namespace std;
int A, B, C;
long long go(long long A, long long B)
{
    if (B == 1)
    {
        return A % C;
    }

    long long a = go(A, B / 2);
    a = (a * a) % C;
    if (B % 2 == 1)
        a = (a * A) % C;
    return a;
}
int main()
{
    cin >> A >> B >> C;

    cout << go(A, B) << "\n";
}
