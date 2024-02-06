#include <bits/stdc++.h>
using namespace std;
int T;
int input;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int ret5 = 0;
        cin >> input;
        for (int j = 5; j <= input; j *= 5)
        {
            ret5 += input / j;
        }
        cout << ret5 << "\n";
    }
}