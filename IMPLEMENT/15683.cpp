#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n,m,map[8][8],turncnt[5]={4,2,4,4,1},dircnt[5]={1,2,2,3,4},ans=99999,show[8][8];
pair<int, int> d1[4][4]={{{0,1},{0,0},{0,0},{0,0}},{{1,0},{0,0},{0,0},{0,0}},{{0,-1},{0,0},{0,0},{0,0}},{{-1,0},{0,0},{0,0},{0,0}}};
pair<int, int> d2[4][4]={{{0,1},{0,-1},{0,0},{0,0}},{{1,0},{-1,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}}};
pair<int, int> d3[4][4]={{{0,-1},{1,0},{0,0},{0,0}},{{1,0},{0,1},{0,0},{0,0}},{{0,1},{-1,0},{0,0},{0,0}},{{-1,0},{0,-1},{0,0},{0,0}}};
pair<int, int> d4[4][4]={{{0,-1},{1,0},{-1,0},{0,0}},{{1,0},{0,1},{0,-1},{0,0}},{{0,1},{-1,0},{1,0},{0,0}},{{-1,0},{0,-1},{0,1},{0,0}}};
pair<int, int> d5[4][4]={{{0,-1},{1,0},{-1,0},{0,1}},{{0,0},{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0},{0,0}}};
vector<pair<int, int> > v;

void paint(int dx, int dy, int x, int y, int p){
    show[x][y]+=p;
    while(0<=x+dx && x+dx<m && 0<=y+dy && y+dy<n && map[x+dx][y+dy]!=6){
        show[x+dx][y+dy]+=p;
        x+=dx;
        y+=dy;
    }
}

void aaa(int vidx){
    if(vidx==v.size()){
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(show[j][i]==0&&map[j][i]!=6)
                    cnt++;
            }
        }
        ans=min(ans,cnt);
        return;
    }
    int curx=v[vidx].first, cury=v[vidx].second, curmap=map[curx][cury];
    pair<int, int> (*d)[4];
    if(curmap==1)
        d=d1;
    else if(curmap==2)
        d=d2;
    else if(curmap==3)
        d=d3;
    else if(curmap==4)
        d=d4;
    else if(curmap==5)
        d=d5;
    for(int i=0;i<turncnt[curmap-1];i++){
        for(int j=0;j<dircnt[curmap-1];j++){
            int dx=d[i][j].first, dy=d[i][j].second;
            paint(dx,dy,curx,cury,1);
        }
        aaa(vidx+1);
        for(int j=0;j<dircnt[curmap-1];j++){
            int dx=d[i][j].first, dy=d[i][j].second;
            paint(dx,dy,curx,cury,-1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[j][i];
            show[j][i]=0;
            if(map[j][i]!=0&&map[j][i]!=6)
                v.push_back(make_pair(j,i));
        }
    }
    aaa(0);
    cout<<ans;
}