#include <bits/stdc++.h>
using namespace std;
int tmp, cnt, N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while (1)
    {
        tmp += 1;
        string strTmp = to_string(tmp);
        for (int i = 0; i < strTmp.length(); i++)
        {
            if (strTmp.substr(i, 3) == "666")
            {
                cnt += 1;
                break;
            }
        }

        if (cnt == N)
        {
            cout << tmp;
            break;
        }
    }
}

// 계속해서 1씩 더하다가 666이 포함되어 있으면 cnt 증가시키기
// 증가시킨 cnt와 N이 동일하다면 해당 값 출력.

// 666이 포함되어 있는지 확인할 수 있다.

// js에서 include 함수는 C++에서 find로 대체할 수 있음.
//  if(string.find(찾을거)!=string::npos) -> 존재한다면
