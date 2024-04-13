#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int T, N, M;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int mp[24][24], visited[24][24];

int cost(int k){
    return k*k + (k-1)*(k-1);
}

int BFS(int y,int x,int k){
    int cntH=0;
    
    queue<pair<int,int > > q;
    q.push({y,x});
    visited[y][x] = 1;
    while(q.size()){
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        if(mp[hy][hx]) cntH+=1;
        if (visited[hy][hx]>=k) continue;
        for(int i=0;i<4;i++){
            int ny= hy + dy[i];
            int nx= hx + dx[i];
            
            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
            if(visited[ny][nx]) continue;
            
            q.push({ny,nx});
            visited[ny][nx] = visited[hy][hx]+1;
        }
    }
  
    return cntH;
}

int main() {
    cin >> T;
    
    for(int t=1;t<=T;t++){
        int k=0,resH=0,homecnt=0;
     fill(&mp[0][0], &mp[0][0] + 24*24,0);   
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&mp[i][j]);
            if(mp[i][j]==1) homecnt+=1;
        }
    }
    while(1){
        k+=1;
        int maxH=0;
        
        if (homecnt*M < cost(k)) break;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                fill(&visited[0][0], &visited[0][0] + 24*24,0);
                maxH = max(BFS(i,j,k), maxH);
            }
        }
        
        if(maxH*M>=cost(k)){
            resH = max(maxH,resH);
        }
    }
    cout <<'#'<<t<<" "<<resH<<"\n";
    }
    return 0;
}



// 8 3
// 00000100
// 01010001
// 00000000
// 00010100
// 00110000
// 00000000
// 00001010
// 10000000