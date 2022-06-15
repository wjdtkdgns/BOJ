#include<iostream>

using namespace std;

int n,m,r,c,d;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},nextd[4]={3,0,1,2};
int map[50][50], visited[50][50];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>r>>c>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            visited[i][j]=0;
        }
    }
    int curx=r,cury=c,curd=d,cntd=0,clean=0;
    while(1){
        if(visited[curx][cury]==0){
            clean++;
            visited[curx][cury]=clean;
        }
        int nextx,nexty,nextdir=curd;
        cntd=0;
        for(int i=0;i<4;i++){
            nextx=curx+dx[nextd[nextdir]];
            nexty=cury+dy[nextd[nextdir]];
            if(0<=nextx&&nextx<n&&0<=nexty&&nexty<m){
                if(visited[nextx][nexty]==0&&!map[nextx][nexty]){
                    curx=nextx;
                    cury=nexty;
                    curd=nextd[nextdir];
                    break;
                }
            }
            nextdir=nextd[nextdir];
            cntd++;
        }
        if(cntd==4){
            if(!map[curx+dx[nextd[nextd[curd]]]][cury+dy[nextd[nextd[curd]]]]){
                curx=curx+dx[nextd[nextd[curd]]];
                cury=cury+dy[nextd[nextd[curd]]];
            }
            else{
                break;
            }
        }
    }
    cout<<clean;
}