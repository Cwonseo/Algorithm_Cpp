#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int mp[60][60], cloud[60][60];
int N, M;
int dy[9] = {-10,0,-1,-1,-1,0,1,1,1};
int dx[9] = {-10,-1,-1,0,1,1,1,0,-1};

void printM(){
    for(int i=0; i <=N+10;i++){
        for(int j=0;j<=N+10;j++){
            cout << cloud[i][j]<<" ";
        }
        cout << "\n";
    }
}
int duplicate(int y,int x){
    int cnt = 0;
    if(mp[y-1][x-1]>0){cnt+=1;}
    if(mp[y-1][x+1]>0){cnt+=1;}
    if(mp[y+1][x-1]>0){cnt+=1;}
    if(mp[y+1][x+1]>0){cnt+=1;}
    return cnt;
}

void move(int d,int s){
    
    int tmpx = 0, tmpy = 0;

    for(int i=0;i<s;i++){
        tmpy+=dy[d];
        tmpx+=dx[d];
    }
    int cloudMp[60][60];
    fill(&cloudMp[0][0], &cloudMp[0][0] +60*60, 0);
    for(int i=1;i<=N;i++){// 1
        for(int j=1;j<=N;j++){
            if(cloud[i][j]){
                int y = (i+tmpy);
                int x = (j+tmpx);
                while(y>N){
                    y -=N;
                }
                while(x >N){
                    x -=N;
                }
                while(y<1){
                    y+=N;
                }
                while(x <1){
                    x+=N;
                }
                cloudMp[y][x] =1;
            }
        }
    }
      
    for(int i=1;i<=N;i++){// 2
        for(int j=1;j<=N;j++){
                cloud[i][j] = cloudMp[i][j];
                if(cloud[i][j] == 1){
                    mp[i][j]+=1;
                }
            }
        }
    for(int i=1;i<=N;i++){// 4
        for(int j=1;j<=N;j++){
             if(cloud[i][j] == 1){
                    mp[i][j]+=duplicate(i,j);
                }
            }
        }
    
    for(int i=1 ; i<=N;i++){// 3, 5
        for(int j=1;j<=N;j++){
            if (cloud[i][j] == 1){
                cloud[i][j] = 0;
                continue;
            }
            if (mp[i][j]>=2){
                cloud[i][j] = 1;
                mp[i][j]-=2;
            }
        }
    }

}


int main(){
    cin >> N >> M;
    for(int i=1; i <=N;i++){
        for(int j=1;j<=N;j++){
            cin >> mp[i][j];
        }
    }
        
    cloud[N][1] = 1;
    cloud[N][2] = 1;
    cloud[N-1][1] = 1;
    cloud[N-1][2] = 1;
    for(int i=1; i<= M; i++){
        int d, s;
        cin >> d >> s;
        move(d,s);
    }
    int res = 0;
    for(int i=1; i <=N;i++){
        for(int j=1;j<=N;j++){
            res+= mp[i][j];
        }
    }
    cout << res;
}