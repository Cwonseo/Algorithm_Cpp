#include <bits/stdc++.h>
using namespace std;
int H, W;
char mp[104][104];
char input;
int main()
{
    cin >> H >> W;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> input;
            mp[i][j] = input;
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int idx = j;
            int cnt = 0;
            while (idx >= 0) // 해당 문자부터 왼쪽으로 시작지점까지 탐색
            {
                if (mp[i][idx] == 'c')
                {
                    cout << cnt << " ";
                    break;
                }
                idx -= 1;
                cnt += 1;
            }
            if (idx < 0)
                cout << idx << " ";
        }
        cout << "\n";
    }
}
//