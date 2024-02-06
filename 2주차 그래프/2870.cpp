#include <bits/stdc++.h>
using namespace std;
int N;
string input;
vector<string> nums;
bool cmp(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int numCheck = 0;
        string splitNum = "";
        cin >> input;
        for (int i = 0; i <= input.length(); i++)
        {
            if ('0' <= input[i] && input[i] <= '9' && i != input.length())
            {

                if (splitNum == "0")
                {
                    splitNum = input[i];
                }
                else
                    splitNum += input[i];
                numCheck = 1;
            }
            else if (numCheck)
            {
                nums.push_back(splitNum);
                splitNum = "";
                numCheck = 0;
            }
        }
    }
    sort(nums.begin(), nums.end(), cmp);
    for (string j : nums)
    {
        cout << j << "\n";
    }
}

// [x] 숫자를 찾을 수 있다.
// [x] 숫자의 앞에 0이 있는 경우 생략한다.
// [x] 숫자가 연속되는지 여부를 알 수 있다.
// [x] 연속된 숫자를 int로 변경할 수 있다.
// [x] 뽑은 숫자들을 오름차순으로 변경할 수 있다.

// 범위를 반드시 보아야 한다.
// 글자수의 범위가 100글자였음. -> int로는 커버할 수 없음. -> string으로 커버하자.

// cmp 함수에서 숫자를 비교할 때는 그냥 아스키코드가 숫자의 크기를 따라 가므로
// a = 121 b = 122 인 경우 그냥 return a < b 를 이용하여 오름차순 정렬이 가능하다.