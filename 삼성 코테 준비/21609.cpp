    #include <stdio.h>
    #include <string.h>
    #include <algorithm>
    #include <queue>
    #include <vector>
    #include <iostream>
    using namespace std;
    int N, M,res;
    int dy[4] = {-1,0,1,0};
    int dx[4] = {0,1,0,-1};
    vector<vector<int>> mp;
    int visited[30][30];
    
    struct Group{
        int num;
        vector<pair<int,int>> pairs;
        int rainbowN;
        int row, col;
    };
    void printM(vector<vector<int>>){
        for(int i=0 ;i <N;i++){
            for(int j=0; j<N;j++){
                cout <<  mp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    Group BFS(int y, int x, int color){
        queue<pair<int,int>> q;
        visited[y][x] = 1;
        q.push({y,x});
        Group now;
        now.num = 0;
        now.rainbowN = 0;
        now.row = 100;
        now.col  = 100;
        while(q.size()){
            int hy = q.front().first;
            int hx = q.front().second;
            q.pop();
            now.num+=1;
            if(mp[hy][hx] == 0) now.rainbowN +=1;
            now.pairs.push_back({hy,hx});
        for(int i=0; i<4;i++){
            int ny = hy + dy[i];
            int nx = hx + dx[i];
            
            if (ny <0 || nx< 0 || ny >= N || nx >=N) continue;
            if (visited[ny][nx]) continue;
            if (mp[ny][nx] !=color && mp[ny][nx] != 0) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
    }
    return now;
    }
    void rotate(){
        vector<vector<int>> tmp(N,vector<int>(N));
        
        for(int i=0; i<N;i++){
            for(int j=0 ; j<N;j++){
                tmp[i][j] = mp[j][N-i-1];
            }
        }
        for(int i=0; i<N;i++){
            for(int j=0 ; j<N;j++){
                mp[i][j] = tmp[i][j];
            }
        }
        
    }
    
    void down(){
        for(int i= N-2;i>=0;i--){
            for(int j=0 ; j <N;j++){
                int tmpi=i;
                if (mp[i][j]!=-1 && mp[i][j]!=-2){
                while(1){
                    if(tmpi+1 >=N || mp[tmpi+1][j] == -1 || mp[tmpi+1][j] !=-2) break;
                    tmpi +=1;
                }
                if(i!=tmpi){
                    mp[tmpi][j] = mp[i][j];
                    mp[i][j] = -2;
                }
                }
            }
        }
    }
    int main(){
        cin >> N >> M;
        mp.resize(N,vector<int>(N));
        for(int i=0 ;i <N;i++){
            for(int j=0; j<N;j++){
                cin >> mp[i][j];
            }
        }
         
        
        
        while(1){
            Group maxG;
            maxG.num = 0;
            maxG.rainbowN = 0;
            
            fill(&visited[0][0],&visited[0][0] + 30*30, 0);
            for(int i=0 ;i <N;i++){
                for(int j=0; j<N;j++){
                if(mp[i][j]>0 && visited[i][j] == 0){
                    Group nowG = BFS(i,j, mp[i][j]);
                    /*cout << i<<j<<" "<< nowG.num<< maxG.num << " "<< nowG.rainbowN<<"\n";*/
                    
                      for(auto i : nowG.pairs){
                          if(mp[i.first][i.second]==0){
                              visited[i.first][i.second] = 0;
                          }
                          if(mp[i.first][i.second]!=0){
                            nowG.row = min(nowG.row,i.first);
                            nowG.col = min(nowG.col,i.second);
                          }
                    }
                    if(nowG.num > maxG.num){
                        maxG = nowG;
                    } else if (nowG.num == maxG.num){
                        if(nowG.rainbowN > maxG.rainbowN){
                        maxG = nowG;
                        }else if (nowG.rainbowN  == maxG.rainbowN){
                            if(nowG.row> maxG.row) maxG = nowG;
                            else if (nowG.row == maxG.row){
                                if (nowG.col>maxG.col) maxG = nowG;
                            }
                        }
                    }
                    }
                }
            }
             if(maxG.num <= 1){
                break;
            }
            for(auto i : maxG.pairs){
                mp[i.first][i.second] = -2;
            }
            
            down();
        
            rotate();
            down();
            
            res += maxG.num * maxG.num;
        
           
        }
        cout << res;
        
    }
    
