#include <bits/stdc++.h>
using namespace std;
string a;
bool check(string a)
{
    stack<char> st;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(' || a[i] == '[')
        {
            st.push(a[i]);
        }
        else if (a[i] == ')')
        {
            if (st.size() == 0 || st.top() != '(')
                return false;

            st.pop();
        }
        else if (a[i] == ']')
        {
            if (st.size() == 0 || st.top() != '[')
                return false;
            st.pop();
        }
    }
    if (st.size() == 0)
        return true;
    else
        return false;
}
int main()
{
    while (1)
    {
        getline(cin, a);
        if (a == ".")
            break;
        if (check(a))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

// 테스트케이스 마다 어떤 로직을 실행하는 문제는 초기화를 잘 하기
//  스택 탑을 참조하고 싶다면 size를 반드시 체크하고 참조하자. 체크하지 않으면 에러가 발생함.