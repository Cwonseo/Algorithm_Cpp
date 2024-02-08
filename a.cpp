#include <bits/stdc++.h>
using namespace std;
int N, input;
int result[1000004], arr[1000004];
stack<int> st;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        while (st.size() && arr[st.top()] < arr[i])
        {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while (st.size())
    {
        result[st.top()] = -1;
        st.pop();
    }
    for (int i = 0; i < N; i++)
    {
        cout << result[i] << " ";
    }
}

// 틀린문제
// 짝짓기 문제임. 짝짓기 문제는 스택으로.