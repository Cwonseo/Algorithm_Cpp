#include <bits/stdc++.h>
using namespace std;
#define prev wonseo
int N;
int team1, team2, goalTeam, team1Time, team2Time;
string goalTime, prev;
string secondToString(int sec)
{
    string tmp = "00" + to_string(sec);

    return tmp.substr(tmp.length() - 2, tmp.length());
}
int stringToSecond(string time)
{
    return atoi(time.substr(0, 2).c_str()) * 60 + atoi(time.substr(3, 2).c_str());
}
int getTime(string goalTime)
{
    return stringToSecond(goalTime) - stringToSecond(prev);
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {

        cin >> goalTeam >> goalTime;

        if (team1 > team2 && i != 0)
        {
            team1Time += getTime(goalTime);
        }
        else if (team1 < team2 && i != 0)
        {
            team2Time += getTime(goalTime);
        }

        if (goalTeam == 1)
            team1 += 1;
        else if (goalTeam == 2)
            team2 += 1;

        prev = goalTime;
    }

    if (team1 > team2)
    {
        team1Time += getTime("48:00");
    }
    else if (team1 < team2)
    {
        team2Time += getTime("48:00");
    }

    cout << secondToString(team1Time / 60) << ":"
         << secondToString(team1Time % 60) << "\n"
         << secondToString(team2Time / 60) << ":"
         << secondToString(team2Time % 60);
}

// substr 쓰는 법 학습
// string.substr(시작지점, 시작지점으로부터 몇칸)
// atoi 쓰는 법 학습
// atoi(s.c_str()) -> string형태의 숫자 int로
// 숫자형태가 아니라면 -1
// 00:00 형식으로 나오게 할 줄 모름.