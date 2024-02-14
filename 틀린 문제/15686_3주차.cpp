#include <bits/stdc++.h>
using namespace std;
int N, M, mp[54][54], minSum = 2000000;
vector<pair<int, int>> chicken, house;
void combi(int start, vector<int> v)
{
    if (v.size() == M)
    {
        int sum = 0;

        for (pair<int, int> j : house)
        {
            int dist = 5000;
            int houseY = j.first;
            int houseX = j.second;
            for (int i : v)
            {
                int chickenY = chicken[i].first;
                int chickenX = chicken[i].second;
                dist = min(dist, abs(houseY - chickenY) + abs(houseX - chickenX));
            }
            sum += dist;
        }
        minSum = min(minSum, sum);
    }
    else
    {
        for (int i = start + 1; i < chicken.size(); i++)
        {
            v.push_back(i);
            combi(i, v);
            v.pop_back();
        }
    }
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 2)
            {
                chicken.push_back({i, j});
            }
            else if (mp[i][j] == 1)
            {
                house.push_back({i, j});
            }
        }
    }
    vector<int> v;
    combi(-1, v);
    cout << minSum;
}

// 로직
// 1. 치킨집들을 벡터에 저장한다.
// 2. 해당 치킨집들 중 M개만큼 선택한다.
// 3. 위 선택하는 과정마다 도시의 치킨거리를 구한다.
// 4. 치킨거리를 구하면서 최소치킨거리를 알아낸다.
//     4-1 선택한 치킨집이 저장된 벡터와 집의 위치가 저장된 벡터를 이용해 구한다.