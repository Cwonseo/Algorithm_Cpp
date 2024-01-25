#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int N;
string word;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmp = "";
        int flag = 0;

        cin >> word;

        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == tmp[tmp.length() - 1])
            {
                tmp.pop_back();
            }
            else
            {
                tmp.push_back(word[i]);
            }
        }

        if (tmp.length() == 0)
        {
            cnt += 1;
        }
    }
    cout << cnt;
}