#include <bits/stdc++.h>
using namespace std;
string str1, str2;
int cnt;
int main()
{
    getline(cin, str1);
    getline(cin, str2);

    for (int i = 0; i < str1.length(); i++)
    {

        if (str1.substr(i, str2.length()).find(str2) != string::npos)
        {
            cnt += 1;
            i += str2.length() - 1;
        }
    }
    cout << cnt;
}