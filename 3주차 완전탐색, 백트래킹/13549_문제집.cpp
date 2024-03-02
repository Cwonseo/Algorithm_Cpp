#include <bits/stdc++.h>
using namespace std;
int N, K,visited[200004],flag,minN = 2000000;

void go(){
    queue<int> q;
    visited[N] = 1;
    q.push(N);
    while(1){
        if (flag) break;
        int qSize = q.size();
        
        for(int j=0;j<qSize;j++){
        int here = q.front();
        q.pop();
        
        if (here ==K){
            minN = min(minN, visited[here]-1);
            flag = 1;
        }
        if (here!=0){
            int next = here*2;
            if (next>0 && next<=150000){
                if(!visited[next]){
                visited[next] = visited[here];
                q.push(next);
               }
            }
        }
         for(int i : {-1,1}){
            int next = here+i;
            if (next<0 || next>150000) continue;
            if(visited[next]) continue;
            visited[next] = visited[here]+1;
            q.push(next);
        }
          
        }
    }

}
int main(){
    cin >> N >> K;
    go();
    cout << minN;
}