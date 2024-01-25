#include <bits/stdc++.h>
using namespace std;
string s, ret;
int main()
{
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z')
        {
            ret += (char)(s[i] + 13);
            if (s[i] + 13 > 'z')
            {
                ret[i] = (char)('a' + (ret[i] - 'z' - 1));
            }
        }
        else if (('A' <= s[i] && s[i] <= 'Z'))
        {
            ret += (char)(s[i] + 13);
            if (s[i] + 13 > 'Z')
            {
                ret[i] = (char)('A' + (ret[i] - 'Z' - 1));
            }
        }
        else
            ret += s[i];
    }
    cout << ret;
}

// - [ ] string 입력받기
// - [ ] 각 string 아스키코드 + 13하기
// - [ ] 해독은 아스키코드 -13하기
// - [ ] 알파벳이 아닌 글자는 적용시키지 않기