#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> ret;
set <vector<int>> sret;
int arr[10],visited[10];

void go(){
    if (ret.size()==M){
        
        sret.insert(ret);
        return;
    }
    for(int i=0;i<N;i++){
        // if(visited[i]) continue;
        ret.push_back(arr[i]);
        // visited[i]=1;
        go();
        ret.pop_back();
        // visited[i]=0;
    }
}
int main(){
    cin >>N >> M;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    go();

    for(vector<int> i : sret){
        for(int j : i){
            cout << j<<" ";
        }
        cout << "\n";
    }
}