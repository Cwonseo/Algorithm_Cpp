#include <bits/stdc++.h>
using namespace std;
const int n = 3;
int visited[n];
vector<int> adj[n];


void dfs(int u){
    cout << u;
    visited[u] = 1;
    for(int i :adj[u]){
        cout << i;
        if (visited[i]) continue;
        dfs(i);
    }
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);
    adj[2].push_back(6);
    // dfs(1);
}