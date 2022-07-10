#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,l,map[100][100], ans=0;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[j][i];
        }
    }
    //세로
    for(int i=0;i<n;i++){
        int cnt=1, j;
        for(j=1;j<n;j++){
            if(map[i][j-1]==map[i][j])
                cnt++;
            else if(map[i][j-1]-1 == map[i][j] && cnt>=0)
                cnt=1-l;
            else if(map[i][j-1]+1 == map[i][j] && cnt>=l)
                cnt=1;
            else
                break;
        }
        if(j==n && cnt>=0)
            ans++;
    }
    //가로
    for(int i=0;i<n;i++){
        int cnt=1, j;
        for(j=1;j<n;j++){
            if(map[j-1][i]==map[j][i])
                cnt++;
            else if(map[j-1][i]-1 == map[j][i] && cnt>=0)
                cnt=1-l;
            else if(map[j-1][i]+1 == map[j][i] && cnt>=l)
                cnt=1;
            else
                break;
        }
        if(j==n && cnt>=0)
            ans++;
    }
    cout<<ans;
}