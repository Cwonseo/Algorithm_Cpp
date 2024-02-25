#include <bits/stdc++.h>
using namespace std;
char sign[14];
long long k, minN = 10000000000, maxN, cnt;
vector<int> now;
int num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int visited[10];
long long toNum()
{
    long long ret = 0;
    for (int i = 0; i < now.size(); i++)
    {
        ret = ret * 10 + now[i];
    }
    return ret;
}
void DFS(int here)
{

    now.push_back(here);
    if (now.size() > k + 1)
        return;

    if (cnt == k)
    {
        maxN = max(maxN, toNum());
        minN = min(minN, toNum());
        return;
    }
    visited[here] = 1;
    for (int next : num)
    {
        if (visited[next])
            continue;
        if (sign[cnt] == '>')
        {
            if (here > next)
            {
                cnt++;
                visited[next] = 1;
                DFS(next);
                cnt--;
                visited[next] = 0;
                now.pop_back();
            }
        }
        else
        {
            if (here < next)
            {
                cnt++;
                visited[next] = 1;
                DFS(next);
                cnt--;
                visited[next] = 0;
                now.pop_back();
            }
        }
    }
}
int main()
{
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> sign[i];
    }
    for (int i = 0; i <= 9; i++)
    {
        now.clear();
        fill(&visited[0], &visited[0] + 10, 0);
        DFS(i);
    }

    string retMax = "000000000" + to_string(maxN);
    string retMin = "000000000" + to_string(minN);
    cout << retMax.substr(retMax.length() - k - 1, retMax.length()) << "\n";
    cout << retMin.substr(retMin.length() - k - 1, retMin.length());
}