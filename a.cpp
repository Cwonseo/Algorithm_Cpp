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