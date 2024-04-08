// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int n, m;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0,1,0,-1};
char mp[20][20];
int visited[20][20][20][20];
int res = -1;
struct pos{
    int ry, rx, by, bx;
    int cnt;
};


void BFS(int ry, int rx, int by, int bx){
    queue<pos> q;
    q.push({ry,rx,by,bx,0});
    visited[ry][rx][by][bx] = 1;

    while(q.size()){
        int hry = q.front().ry;
        int hrx = q.front().rx;
        int hby = q.front().by;
        int hbx = q.front().bx;
        int cnt = q.front().cnt;
        
        q.pop();
        if(cnt>10) {
            // visited[hry][hrx][hby][hbx] = 0;
            break;
        }
        if(mp[hby][hbx] == 'O'){continue;}
        if(mp[hry][hrx] == 'O') {
                res = cnt;
                break;
            }
        
        for(int i=0;i<4;i++){
            int nry = hry;
            int nrx = hrx;
            int nby = hby;
            int nbx = hbx;
            int  Rcnt = 0, Bcnt = 0;
            while(1){
                if (mp[nry][nrx] == 'O'){ 
                    break;
                }
                if (mp[nry + dy[i]][nrx + dx[i]] == '#') {break;}
                nry = nry + dy[i];
                nrx = nrx + dx[i];
                Rcnt+=1;
            }
            while(1){
                if (mp[nby][nbx] == 'O'){ 
                    break;
                }
                if (mp[nby + dy[i]][nbx + dx[i]] == '#') break;
                nby = nby + dy[i];
                nbx = nbx + dx[i];
                Bcnt+=1;
            }
            
            if (nry == nby && nrx == nbx  && mp[nry][nrx] != 'O'){
                if (Rcnt> Bcnt){
                    nry = nry - dy[i];
                    nrx = nrx - dx[i];
                    
                } else {
                    nby = nby - dy[i];
                    nbx = nbx - dx[i];
                    }
                
            }
            if (visited[nry][nrx][nby][nbx]) continue;
            visited[nry][nrx][nby][nbx] = 1;
            q.push({nry,nrx,nby,nbx,cnt+1});
        }
        
    }
    
}

int main() {
    // Write C++ code here
    int by,bx,ry,rx;
    cin >> n >> m;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mp[i][j];
            if (mp[i][j] == 'B') {
                by = i;
                bx = j;
            }
            else if (mp[i][j]=='R'){
                ry = i;
                rx = j;
            }
        }
    }
    

    BFS(ry,rx,by,bx);
    
    cout << res;
    
    return 0;
}