#include <bits/stdc++.h>
using namespace std;
int L, C, visited[19];
char chars[19];
char gather[] = {'a', 'e', 'i', 'o', 'u'};
string ret;
void go(int here)
{
    if (ret.size() == L)
    {
        int cnt = 0;
        for (char c : gather)
        {
            if (ret.find(c) != string::npos)
            {
                cnt++;
            }
        }
        if (cnt > 0 && ret.size() - cnt > 1)
        {
            for (char c : ret)
            {
                cout << c;
            }
            cout << "\n";
        }
        return;
    }
    for (int i = here; i < C; i++)
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        ret.push_back(chars[i]);
        go(i);
        visited[i] = 0;
        ret.pop_back();
    }
}
int main()
{
    cin >> L >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> chars[i];
    }
    sort(chars, chars + C);

    go(0);
}

// 정렬 먼저 하고
//  dfs 돌려서  size가 L과 같아지면 출력하고 return;

// 최소 한개의 모음과 두개의 자음을 찾아라.
