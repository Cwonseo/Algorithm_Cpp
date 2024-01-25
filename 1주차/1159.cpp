#include <bits/stdc++.h>
using namespace std;
int N;
string player[150];
string result[150];
int cnt[27];
int flag = 0;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> player[i];
    }

    for (int i = 0; i < N; i++)
    {
        cnt[player[i][0] - 'a'] += 1;
    }
    for (int i = 0; i <= 'z' - 'a'; i++)
    {
        if (cnt[i] >= 5)
        {
            cout << char(i + 'a');
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "PREDAJA";
}