#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<int> em[100001];
    int start, dp[100001]={0, };
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(a==-1)
            start=i;
        else
            em[a].push_back(i);
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        dp[a]+=b;
    }
    queue<int> q;
    q.push(start);
    dp[start]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<em[cur].size();i++){
            dp[em[cur][i]] += dp[cur];
            q.push(em[cur][i]);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
}