#include <bits/stdc++.h>
using namespace std;
int N;
string p, before, after, file[101];
int main()
{
    cin >> N;
    cin >> p;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '*')
        {
            before = p.substr(0, i);
            after = p.substr(i + 1, p.size());
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cin >> file[i];
    }
    for (int i = 0; i < N; i++)
    {

        if (file[i].size() + 1 < p.size())
        {
            cout << "NE "
                 << "\n";
            ;
        }
        else if (before == file[i].substr(0, before.size()) && (after == file[i].substr(file[i].size() - after.size(), file[i].size())))
        {

            cout << "DA"
                 << "\n";
        }
        else
        {
            cout << "NE"
                 << "\n";
        }
    }
}

// - [ ] 별표를 알파벳 소문자로 이루어진 문자열이나 빈 문자열로 변환.
// - [ ] 패턴을 분석하여 * 이전의 string과 이후의 string으로 나눌 수 있다.
// - [ ] * 이전 스트링의 길이만큼 파일이름의 시작지점부터 동일한지 확인할 수 있다.
// - [ ] * 이후 스트링의 길이만큼 파일이름의 끝지점부터 동일한지 확인할 수 있다.

// substr에 첫번째 인자만 넣게 되면 끝까지 뽑아줌.