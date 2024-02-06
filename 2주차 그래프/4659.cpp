#include <bits/stdc++.h>
using namespace std;
string input;

int main()
{
    while (1)
    {
        bool acceptable = true;
        int include = 0;
        int aCount = 0, bCount = 0;
        int sameCnt = 0;
        cin >> input;
        if (input == "end")
            break;

        for (int i = 0; i < input.length(); i++) // 모음 포함하는지 체크
        {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
            {
                include = 1;
            }
        }
        if (include == 0)
            acceptable = false;

        for (int i = 1; i < input.length(); i++) // 같은 글자 연속 2개 체크
        {
            if (input[i] == input[i - 1] && input[i] != 'e' && input[i] != 'o')
            {
                sameCnt += 1;
            }
            else
                sameCnt = 0;

            if (sameCnt >= 1)
            {
                acceptable = false;
            }
        }

        for (int i = 1; i < input.length(); i++) // 자음이나 모음 연속 3개 체크
        {
            if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
            {
                bCount = 0;
                if (input[i - 1] == 'a' || input[i - 1] == 'e' || input[i - 1] == 'i' || input[i - 1] == 'o' || input[i - 1] == 'u')
                {
                    aCount += 1;
                }
            }
            else if (input[i] != 'a' && input[i] != 'e' && input[i] != 'i' && input[i] != 'o' && input[i] != 'u')
            {
                aCount = 0;
                if (input[i - 1] != 'a' && input[i - 1] != 'e' && input[i - 1] != 'i' && input[i - 1] != 'o' && input[i - 1] != 'u')
                {
                    bCount += 1;
                }
            }

            if (aCount >= 2 || bCount >= 2)
            {
                acceptable = false;
            }
        }
        if (acceptable)
        {
            cout << "<" << input << "> is acceptable.\n";
        }
        else
        {
            cout << "<" << input << "> is not acceptable.\n";
        }
    }
}

// [x] 모음이 포함되어 있는가?
// [x] 모음이나 자음이 연속 3개인가?
// [x] 같은 글자가 연속으로 2번 왔는가?
// [x] ee와 oo인가?
