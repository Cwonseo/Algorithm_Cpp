#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int N,res = 0, cnt = 0;
vector<vector<int>> map;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<vector<int>> U(vector<vector<int>> mp){
    for(int i = 0 ;i < N ;i ++){
        for(int j= 0; j< N;j++){
            if(mp[i][j]!='0'){
                int tmpi = i;
            while(1){
                if(tmpi==0 || mp[tmpi-1][j]!=0) break;
                tmpi -=1;
            }
            mp[tmpi][j] = mp[i][j];
            if (tmpi!=i)
            mp[i][j] = 0;
            }
        }
    }
    return mp;
}
vector<vector<int>> Umerge(vector<vector<int>> mp){
    for(int i=1;i<N;i++){
        for(int j=0;j<N;j++){
            if(mp[i][j]!='0' && mp[i-1][j] == mp[i][j]){
                mp[i][j] = 0;
                mp[i-1][j] *=2;
            }
        }
    }
   return U(mp);
}
vector<vector<int>> R(vector<vector<int>> mp){
    for(int i = 0 ;i < N ;i++){
        for(int j= N-1; j>= 0;j--){
            if(mp[i][j]!='0'){
                int tmpj = j;
            while(1){
                if(tmpj ==N-1 ||mp[i][tmpj+1]!=0 ) break;
                tmpj+=1;
            }
            mp[i][tmpj] = mp[i][j];
            if (tmpj!=j)
            mp[i][j] = 0;
            }
        }
    }
    return mp;
}
vector<vector<int>> Rmerge(vector<vector<int>> mp){
    for(int i=0;i<N;i++){
        for(int j=N-1;j>0;j--){
            if(mp[i][j]!='0' && mp[i][j-1] == mp[i][j]){
                mp[i][j] *= 2;
                mp[i][j-1] =0;
            }
        }
    }
    return R(mp);
}
vector<vector<int>> D(vector<vector<int>> mp){
    for(int i = N-1 ;i >=0 ;i--){
        for(int j= 0; j< N;j++){
            if(mp[i][j]!='0'){
                int tmpi = i;
            while(1){
                if(tmpi==N-1 || mp[tmpi+1][j]!=0) break;
                tmpi +=1;
            }
            mp[tmpi][j] = mp[i][j];
            if (tmpi!=i)
            mp[i][j] = 0;
            }
        }
    }
    return mp;
}
vector<vector<int>> Dmerge(vector<vector<int>> mp){
    for(int i=N-1;i>0;i--){
        for(int j=0;j<N;j++){
            if(mp[i][j]!='0' && mp[i-1][j] == mp[i][j]){
                mp[i][j] *= 2;
                mp[i-1][j] =0;
            }
        }
    }
    return D(mp);
}
vector<vector<int>> L(vector<vector<int>> mp){
    for(int i = 0 ;i < N ;i++){
        for(int j= 0; j<N ;j++){
            if(mp[i][j]!='0'){
                int tmpj = j;
            while(1){
                if(tmpj == 0 ||mp[i][tmpj-1]!=0 ) break;
                tmpj-=1;
            }
            mp[i][tmpj] = mp[i][j];
            if (tmpj!=j)
            mp[i][j] = 0;
            }
        }
    }
    return mp;
}

vector<vector<int>> Lmerge(vector<vector<int>> mp){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mp[i][j]!='0' && mp[i][j+1] == mp[i][j]){
                mp[i][j] *= 2;
                mp[i][j+1] =0;
            }
        }
    }
    return L(mp);
}
void getMax(vector<vector<int>> mp){
    for(int i=0; i<N;i++){
        for(int j=0 ;j<N;j++){
         res = max(res,mp[i][j]);
        }
}
}
void printM(vector<vector<int>> nowMp){
for(int i=0; i<N;i++){
        for(int j=0 ;j<N;j++){
            cout<< nowMp[i][j]<<" ";
        }
        cout << "\n";
}
}
void BFS(){
    queue <vector<vector<int>>> q;
    q.push(map);
    while(q.size()){
        int Qsize = q.size();
        for(int j=0 ; j<Qsize ; j++){
            vector<vector<int>> nowMp = q.front();
        q.pop();
        if (cnt==5){
            getMax(nowMp);
            continue;
        }else if (cnt ==6){
            break;
        }
         for(int i=1;i<=4;i++){
            if (i ==1){
                q.push(Umerge(U(nowMp)));
            }else if (i==2){
                q.push(Rmerge(R(nowMp)));
            }else if (i == 3){
                q.push(Dmerge(D(nowMp)));
            }else if (i==4){
                q.push(Lmerge(L(nowMp)));
            }
        }
        }
        cnt+=1;
    }
   
}


int main() {
     cin >> N;
     map.resize(N, vector<int> (N));
    for(int i=0; i<N;i++){
        for(int j=0 ;j<N;j++){
            cin >> map[i][j];
        }
    }   
    
    
    BFS();
    cout << res;
    return 0;
}


