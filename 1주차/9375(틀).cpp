#include <bits/stdc++.h>
using namespace std;
int tc, n;
string name, type, typeName[30];
int main()
{
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        map<string, int> mp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> type;
            mp[type] += 1;
        }
        int res = 1;
        for (auto i : mp)
        {
            res *= (i.second + 1);
        }
        // combi(-1, b, k)
        cout << res - 1 << "\n";
    }
}

// map을 사용하는 법 잘 알기(자료구조)

// 맵 선언 : map<자료형, 자료형> 변수명;
// 맵 value에 수 추가 : map[key] +=1;
// 맵 순회 : for(auto i : map){ 내부에서 i.first로 key, i.second로 value 사용}
