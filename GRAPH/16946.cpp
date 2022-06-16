#include<iostream>
#include<vector>

using namespace std;

int n,m, adj[1000][1000], dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
bool map[1000][1000], visited[1000][1000];
vector<int> v;

void aaa(int x, int y, int num){
    adj[x][y]=num;
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int nextx=x+dx[i];
        int nexty=y+dy[i];
        if(nextx>=0&&nextx<m){
            if(nexty>=0&&nexty<n){
                if(!visited[nextx][nexty]&&!map[nextx][nexty]){
                    aaa(nextx,nexty,num);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        for(int j=0;j<m;j++){
            map[j][i]=a[j]-'0';
            adj[j][i]=0;
            visited[j][i]=0;
        }
    }
    v.push_back(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!map[j][i]&&!adj[j][i]){
                aaa(j,i,v.size());
                v.push_back(0);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v[adj[j][i]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[j][i]!=0){
                int temp=0;
                vector<int> tempv;
                for(int k=0;k<4;k++){
                    int nextx=j+dx[k];
                    int nexty=i+dy[k];
                    if(nextx>=0&&nextx<m){
                        if(nexty>=0&&nexty<n){
                            bool plus=1;
                            for(int q=0;q<tempv.size();q++){
                                if(tempv[q]==adj[nextx][nexty]){
                                    plus=0;
                                }
                            }
                            if(plus&&!map[nextx][nexty]){
                                tempv.push_back(adj[nextx][nexty]);
                                temp+=v[adj[nextx][nexty]];
                            }
                        }
                    }
                } 
                cout<<(temp+1)%10;
            }
            else{
                cout<<0;
            }
        }
        cout<<'\n';
    }
}