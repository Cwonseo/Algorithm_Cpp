#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ret;
void go(int here)
{

    if (ret.size() == M)
    {
        for (int i : ret)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = here; i <= N; i++)
    {
        ret.push_back(i);
        go(i);
        ret.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    go(1);
}