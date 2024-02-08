#include <bits/stdc++.h>
using namespace std;
int N, delN, input, cnt;
vector<int> root;
vector<int> tree[51];
void findLeaf(int node)
{
    if (node == delN)
        return;
    for (int i : tree[node])
    {
        if (i == delN)
        {
            tree[node].erase(find(tree[node].begin(), tree[node].end(), delN));
        }
    }
    if (tree[node].size() == 0)
    {
        cnt += 1;
        return;
    }
    else
    {
        for (int i : tree[node])
        {
            findLeaf(i);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (input == -1)
        {
            root.push_back(i);
        }
        else
            tree[input].push_back(i);
    }
    cin >> delN;
    for (int i : root)
    {
        findLeaf(i);
    }
    cout << cnt;
}

// 트리 문제를 푸는 방식
// 1. 트리는 루트노드부터 탐색하는게 좋다.
// 2. for there adj[here]에서 there가 없는게 리프노드임

// erase사용하지 않고 continue 사용해서 노드 삭제 가능함.
//