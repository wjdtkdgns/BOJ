#include<iostream>

using namespace std;

// https://www.acmicpc.net/problem/15552 참고바람

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int map[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            map[i][j]=a+map[i-1][j]+map[i][j-1]-map[i-1][j-1];
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<map[c][d]-map[a-1][d]-map[c][b-1]+map[a-1][b-1]<<'\n';
        // cout<<map[c][d]<<" "<<map[a-1][d]<<" "<<map[c][b-1]<<" "<<map[a-1][b-1]<<endl;
    }
}