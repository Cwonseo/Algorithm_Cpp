#include <bits/stdc++.h>
using namespace std;
int N, M,num[14],visited[14];
vector<int> arr;
set<vector<int>> ret;
void go(int here){
    if(arr.size()==M){
        ret.insert(arr);

        return;
    }

    for(int i=here;i<N;i++){
        if (visited[i]) continue;
        visited[i] = 1;
        arr.push_back(num[i]);
        go(i);
        visited[i] = 0;
        arr.pop_back();
    }
}
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> num[i];
    }
    sort(num,num+N);
    go(0);

    for(auto i : ret){
        for(int j : i){
            cout << j<<" ";
        }
        cout << "\n";
    }
}


//set 이용하여 중복되는 벡터 제거