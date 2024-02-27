#include <bits/stdc++.h>
using namespace std;
int visited[7][7],scnt,cnt,visited2[7][7];
char mp[7][7];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
set <vector<int>> ret;
void check(int y,int x,vector<int>v){
    visited2[y][x] = 1;
    if (cnt == 7){
        ret.insert(v);
        return;
    }

    for(int i=0;i<4;i++){
        int ny = dy[i]+y;
        int nx = dx[i]+x;
        if (visited2[ny][nx]) continue;
        if (ny<0 || nx<0 || ny>=5 || nx>=5) continue;
        if (visited[ny][nx] == 1){
            cnt++;
            check(ny,nx,v);
        }
    }
}
void combi(int start , vector<int>v){
    if (v.size() == 7){
        scnt = 0,cnt = 1;
        fill(&visited[0][0],&visited[0][0] + 7*7,0);
        fill(&visited2[0][0],&visited2[0][0] + 7*7,0);
        for(int i : v){
            int y = i / 5;
            int x = i % 5;
            if (mp[y][x] =='S') scnt+=1;
            visited[y][x] = 1;
        }
        if (scnt>=4)
        check(v[0]/5,v[0]%5,v);
    
        return;
    }
    for(int i = start+1 ; i<25;i++){
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
}
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >>mp[i][j];
        }
    }
    vector<int> v;
    combi(-1,v);
    cout << ret.size();
}