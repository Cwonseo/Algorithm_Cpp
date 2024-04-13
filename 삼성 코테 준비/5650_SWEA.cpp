#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

int N, mp[120][120];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int resCnt = 0;
int changeDir(int ty, int tx, int d){
    int dir = d;
        
        if (mp[ty][tx] == 1){
            if(dir==0 || dir == 1) dir+=2;
            else if(dir==2) dir-=1;
            else if (dir==3) dir+=1;
        }
        else if (mp[ty][tx] == 2){
            if(dir==1 || dir == 2) dir+=2;
            else if(dir==3) dir-=1;
            else if (dir==0) dir+=1;
        }
        else if (mp[ty][tx] == 3){
            if(dir==2 || dir == 3) dir+=2;
            else if(dir==0) dir-=1;
            else if (dir==1) dir+=1;
        }
        else if (mp[ty][tx] == 4){
            if(dir==0 || dir == 3) dir+=2;
            else if(dir==1) dir-=1;
            else if (dir==2) dir+=1;
        }
        else if (mp[ty][tx] == 5){
            dir+=2;
        }
        while(dir>=4) dir-=4;
        while(dir<0)  dir+=4;
        return dir;
}
int move(int y, int x, int dir){
    int ty = y, tx = x,tdir=dir, cnt = 0;
        while(1){
            ty = ty+dy[tdir];
            tx = tx+dx[tdir];
            // cout <<tdir<< ty<< tx<<" "<<mp[ty][tx]<< "\n";
            if(ty == y && tx == x) {
                return cnt;}
            if(ty<0){cnt+=1; tdir = 2;}
            else if(tx<0){ cnt+=1; tdir = 1;}
            else if(ty>=N){ cnt+=1; tdir = 0;}
            else if(tx>=N){ cnt+=1; tdir = 3;}
            else if(mp[ty][tx]!=0){
                if(mp[ty][tx]>=6 && mp[ty][tx] <=10){
                    int flag=0;
                    for(int i=0;i<N;i++){
                        for(int j=0;j<N;j++){
                            if(mp[i][j] == mp[ty][tx]){
                                // cout <<"change "<< i<<j<<" "<<ty<<tx<<"\n";
                                if(i!=ty || j!=tx){
                                    ty = i; tx = j;
                                    flag=1;
                                    break;
                                }
                            }
                        }
                        if(flag) break;
                    }
                }
                else if (mp[ty][tx]==-1) return cnt;
                else{
                tdir = changeDir(ty,tx,tdir);
                cnt+=1;
                }
            } 
            
            
        }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
	    
	int maxCnt = 0;
	cin >> N;
	fill(&mp[0][0],&mp[0][0]+N*N,0);
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
            cin >> mp[i][j];
        }
    }	
// 	for(int i=0; i<N;i++){
// 	    for(int j=0;j<N;j++){
// 	        scanf("%1d",&mp[i][j]);
// 	        if (0>mp[i][j] && mp[i][j]>9){
// 	            j-=1;
// 	        }
// 	    }
// 	}
    
    for(int i=0; i<N;i++){
	    for(int j=0;j<N;j++){
	        if(mp[i][j] == 0){
	            maxCnt = max(maxCnt,move(i,j,0)); 
	            maxCnt = max(maxCnt,move(i,j,1));
	            maxCnt = max(maxCnt,move(i,j,2));
	            maxCnt = max(maxCnt,move(i,j,3));
	        }
	    }
	}
    cout <<"#"<<test_case<<" " <<maxCnt<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}