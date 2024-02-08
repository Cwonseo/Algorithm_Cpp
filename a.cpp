#include <bits/stdc++.h>
using namespace std;
int N, M, A, B;
vector<int> adj[10004];
vector<int> result;
int checked[10004];
int childNum, maxChildNum;
void dfs(int node)
{
    checked[node] += 1;
    childNum += 1;

    for (int there : adj[node])
    {
        if (checked[there] == 0)
            dfs(there);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        adj[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
    {
        fill(&checked[0], &checked[0] + 10004, 0);
        childNum = 0;
        dfs(i);
        if (childNum > maxChildNum)
        {
            result.clear();
            result.push_back(i);
            maxChildNum = childNum;
        }
        else if (childNum == maxChildNum)
        {
            result.push_back(i);
        }
    }
    sort(result.begin(), result.end());
    for (int i : result)
    {
        cout << i << " ";
    }
}

// map 형식으로 안나왔지만 DFS 써서 풀었음.