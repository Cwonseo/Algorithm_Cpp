#include <bits/stdc++.h>
using namespace std;
int N;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<char> v;
        int flag = 0;
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {

            if (input[j] == '(')
            {
                v.push_back(input[j]);
            }
            else if (input[j] == ')')
            {
                if (v.size() == 0)
                {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }
                v.pop_back();
            }
        }
        if (flag == 0)
        {
            if (v.size() == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}