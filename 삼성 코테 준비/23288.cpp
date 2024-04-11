#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int N, M, K, dir = 'R';
int res =0;
int mp[24][24], diceY, diceX;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int visited[24][24];
int dice[3][3] = {
    {0,2,0},
    {4,1,3},
    {0,5,0},
    };
int diceVal = 6;
char dirArray[4] = {'R','D','L','U'};
int nowDir = 0;
void duplicate(int (&dice1)[3][3], int (&dice2)[3][3]){
    for(int i=0;i<3;i++){// 현재 다이스 복사
        for(int j=0;j<3;j++){
            dice1[i][j] = dice2[i][j];
        }
    }
}
void roll(int move){
    int tmpDice[3][3];
    duplicate(tmpDice,dice);
    
    if(move == 'R'){
        tmpDice[1][0] = diceVal;
        tmpDice[1][1] = dice[1][0];
        tmpDice[1][2] = dice[1][1];
        diceVal = dice[1][2];
    }
     else if(move == 'L'){
        tmpDice[1][2] = diceVal;
        tmpDice[1][1] = dice[1][2];
        tmpDice[1][0] = dice[1][1];
        diceVal = dice[1][0];
    }
     else if(move == 'U'){
        tmpDice[0][1] = dice[1][1];
        tmpDice[1][1] = dice[2][1];
        tmpDice[2][1] = diceVal;
        diceVal = dice[0][1];
    } else if(move == 'D'){
        tmpDice[0][1] = diceVal;
        tmpDice[1][1] = dice[0][1];
        tmpDice[2][1] = dice[1][1];
        diceVal = dice[2][1];
    }
    duplicate(dice,tmpDice);
}

int BFS(int y,int x){
    fill(&visited[0][0], &visited[0][0] + 24*24,0);
    queue<pair<int,int>> q;
    int cnt = 0;
    q.push({y,x});
    visited[y][x] = 1;
    
    while(q.size()){
        int hy = q.front().first;
        int hx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = hy + dy[i];
            int nx = hx + dx[i];
            
            if(ny <0 || nx <0 || ny>=N || nx >=M) continue;
            if (visited[ny][nx]) continue;
            if(mp[hy][hx]!= mp[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
        
    }
    
    for(int i=0;i <N;i++){
        for(int j=0;j<M;j++){
            if (visited[i][j]) cnt+=1;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> mp[i][j];
        }
    }
    
    for(int i=0;i<K;i++){
        
        if (dirArray[nowDir] == 'R') diceX +=1;
        else if (dirArray[nowDir] == 'L') diceX -=1;
        else if (dirArray[nowDir] == 'U') diceY -=1;
        else if (dirArray[nowDir] == 'D') diceY +=1;
        
        if(diceX<0) {diceX+=2; nowDir = 0;}
        else if(diceX>=M) {diceX-=2; nowDir = 2;}
        else if(diceY<0) {diceY+=2; nowDir = 1;}
        else if(diceY>=N) {diceY-=2; nowDir = 3;}
        
        roll(dirArray[nowDir]);
        res+=BFS(diceY,diceX) * mp[diceY][diceX];
        
        
        if (diceVal > mp[diceY][diceX]){
            nowDir+=1;
        }
        else if (diceVal < mp[diceY][diceX]){
            nowDir-=1;
        }
        if (nowDir<0) nowDir = 3;
        else if (nowDir == 4) nowDir = 0;
        
    }
    
 
    cout << res;
}