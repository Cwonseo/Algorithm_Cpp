#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
map<int,int> map_first;
vector <pair<int,int>> v;
int N, C, num;
 bool cmp (pair<int,int> a, pair<int,int> b){
if (a.first == b.first){
return map_first[a.second] < map_first[b.second];
}else {
    return a.first > b.first;
}
}
int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        mp[num] += 1;   
        if(map_first[num] == 0) map_first[num] = i+1;
    }
for(auto i: mp){
    v.push_back({i.second,i.first});
}
sort(v.begin(),v.end(),cmp);
for(auto i : v){
    for(int j =0 ;j<i.first;j++)
    cout << i.second << " ";
}
}