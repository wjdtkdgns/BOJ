#include<iostream>

using namespace std;

bool temp[1001][1001]={0,};
char map[1001][1001];
int n,m, visited[1001][1001]={0,},cnt=1;

int dfs(int x, int y){
    // cout<<x<<" "<<y<<endl;
    temp[x][y]=1;
    int rtn=999999;
    if(map[x][y]=='D'){
        if(y+1<n){
            if(!temp[x][y+1]&&!visited[x][y+1]){
                rtn=dfs(x,y+1);
                visited[x][y]=rtn;
            }
            if(visited[x][y+1]){
                visited[x][y]=visited[x][y+1];
                return visited[x][y+1];
            }
        }
    }
    else if(map[x][y]=='R'){
        if(x+1<m){
            if(!temp[x+1][y]&&!visited[x+1][y]){
                rtn=dfs(x+1,y);
                visited[x][y]=rtn;
            }
            if(visited[x+1][y]){
                visited[x][y]=visited[x+1][y];
                return visited[x+1][y];
            }
        }
    }
    else if(map[x][y]=='U'){
        if(y-1>=0){
            if(!temp[x][y-1]&&!visited[x][y-1]){
                rtn=dfs(x,y-1);
                visited[x][y]=rtn;
            }
            if(visited[x][y-1]){
                visited[x][y]=visited[x][y-1];
                return visited[x][y-1];
            }
        }
    }
    else if(map[x][y]=='L'){
        if(x-1>=0){
            if(!temp[x-1][y]&&!visited[x-1][y]){
                rtn=dfs(x-1,y);
                visited[x][y]=rtn;
            }
            if(visited[x-1][y]){
                visited[x][y]=visited[x-1][y];
                return visited[x-1][y];
            }
        }
    }
    if(rtn==999999){
        cnt++;
        visited[x][y]=cnt-1;
        return cnt-1;
    }
    else{
        return rtn;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            map[j][i]=str[j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[j][i]){
                dfs(j,i);
            }
        }
    }
    cout<<cnt-1;
}