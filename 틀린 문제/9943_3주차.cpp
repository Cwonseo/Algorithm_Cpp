#include <bits/stdc++.h>
using namespace std;
int K, nodeNum, input, visited[10000];
vector<int> building;
vector<int> ret[14];
int getNodeNum()
{
    int num = 1;
    for (int i = 0; i < K; i++)
    {
        num = num * 2;
    }
    return num - 1;
}

void bfs(int sN, int fN, int lv)
{
    if (sN > fN)
        return;
    if (fN == sN)
    {
        ret[lv].push_back(building[fN]);
        return;
    }

    ret[lv].push_back(building[(sN + fN) / 2]);

    bfs(sN, (sN + fN) / 2 - 1, lv + 1);
    bfs((sN + fN) / 2 + 1, fN, lv + 1);
    return;
}
int main()
{
    cin >> K;
    nodeNum = getNodeNum();

    for (int i = 0; i < nodeNum; i++)
    {
        cin >> input;
        building.push_back(input);
    }

    bfs(0, nodeNum - 1, 1);

    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}

// 인자에 레벨을 넣어서 재귀 돌리기.
// visited 함수 굳이 필요하지 않음.

// ret 배열을 10으로 딱 맞게 놨을 때 틀렸다고 뜸.
//  1단계부터 10단계여서 11까지 있었어야 했던 것 같음.
//  다음부터는 넉넉하게 배열 크기 두기.