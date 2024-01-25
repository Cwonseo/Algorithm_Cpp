#include <bits/stdc++.h>
using namespace std;
// 4:08
string s;

string res, odd;
int main()
{
    vector<string> v;
    cin >> s;
    sort(s.begin(), s.end());

    while (s.length() != 0)
    {
        if (s[0] != s[1])
        {
            odd += s[0];
            s.erase(0, 1);
        }
        else
        {
            res += s[0];
            s.erase(0, 2);
        }
    }
    if (odd.length() > 1)
        cout << "I'm Sorry Hansoo";
    else
    {
        cout << res;
        reverse(res.begin(), res.end());
        cout << odd << res;
    }
}

// 하 문자열 sort 사용 시 sort(s.begin(),s.end()) 사용.
// reverse 사용 시에도 위와 같음.