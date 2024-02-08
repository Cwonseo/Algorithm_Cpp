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
// 틀린 이유 1. 짝짓기 문제라고 생각을 못해냈음
// 틀린 이유 2. 스택을 쓸 때 하나하나씩만 짝짓는것 뿐 아니라 하나가 들어와서 여러개를 짝짓(폭발)는 경우 학습되어 있지 않았음.

// 입력받은 순서대로 저장할 배열
// 짝짓기를 위한 스택
// 오큰수를 넣어줄 배열
// 총 3개의 자료구조가 필요했음.
