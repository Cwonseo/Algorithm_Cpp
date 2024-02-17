#include <bits/stdc++.h>
using namespace std;
int N, maxN = -100000000;
char input;
vector<int> num;
vector<char> oper;
int cal(int a, int b, char o)
{
    if (o == '+')
    {
        return a + b;
    }
    if (o == '-')
    {
        return a - b;
    }
    if (o == '*')
    {
        return a * b;
    }
}
void go(int idx, int ret)
{

    if (idx == num.size() - 1)
    {
        maxN = max(ret, maxN);
        return;
    }
    go(idx + 1, cal(ret, num[idx + 1], oper[idx]));
    if (idx < num.size() - 2)
    {
        int tmp = cal(num[idx + 1], num[idx + 2], oper[idx + 1]);
        go(idx + 2, cal(ret, tmp, oper[idx]));
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> input;
        if (i % 2 == 0)
        {
            oper.push_back(input);
        }
        else
        {
            num.push_back(input - '0');
        }
    }
    go(0, num[0]);
    cout << maxN;
}

// 짝짓기 문제 -> 스택을 사용하자.
// 1. 괄호가 포함된 식을 계산하여 수식 내에 괄호를 없앤다.
// 2. 남은 수식을 계산한다.

// 괄호가 들어갈 두 곳을 선택하여 넣는다.

// 방향성을 정하면 된다.
// 완전탐색을 할 때는 인덱스를 기반으로 로직(탐색)을 짤 생각을 해야함
//  -> DAG 방향성은 있고 사이클은 없는 그래프 기반으로 탐색하라.

// 완전탐색은 무조건 기저사례를 먼저 세워야 한다.

// 여기서는 경우의 수가 2개였던 것이다.
