#include <bits/stdc++.h>
using namespace std;
string input, inputTmp;
int main()
{
    cin >> input;
    inputTmp = input;
    reverse(input.begin(), input.end());
    if (input == inputTmp)
    {
        cout << 1;
    }
    else
        cout << 0;
}