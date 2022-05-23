#include<iostream>
#include<cstring>
#include<vector>
#include<climits>
#include<queue>

// 위상 정렬
// 진입노드가 0인 것의 간선을 지워나가면됨.

using namespace std;

int t,n,k,node[1001],target,dp[1001];
int in[1001]={0, };
vector<int> v[1001];
vector<int> topological;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        memset(in,0,sizeof(in));
        topological.clear();
        for(int j=1;j<=n;j++){
            cin>>node[j];
            v[j].clear();
            dp[j]=-INT_MAX;
        }
        for(int j=0;j<k;j++){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            in[b]++;
        }
        cin>>target;
        queue<int> q;
        for(int j=1;j<=n;j++){
            if(!in[j]){
                q.push(j);
                dp[j]=node[j];
            }
        }
        for(int j=0;j<n;j++){
            int cur=q.front();
            q.pop();
            topological.push_back(cur);
            for(int k=0;k<v[cur].size();k++){
                in[v[cur][k]]--;
                if(in[v[cur][k]]==0)
                    q.push(v[cur][k]);
            }
        }
        // for(int j=0;j<n;j++){
        //     cout<<topological[j]<<" ";
        // }
        // cout<<endl;
        for(int j=0;j<n;j++){
            int cur=topological[j];
            for(int k=0;k<v[cur].size();k++){
                // cout<<cur<<" "<<v[cur][k]<<" "<<dp[v[cur][k]]<<" "<<dp[cur]+node[v[cur][k]]<<endl;
                if(dp[v[cur][k]]<dp[cur]+node[v[cur][k]]){
                    // cout<<cur<<" "<<v[cur][k]<<" "<<dp[cur]+node[v[cur][k]]<<endl;
                    dp[v[cur][k]]=dp[cur]+node[v[cur][k]];
                }
            }
        }
        // for(int j=1;j<=n;j++){
        //     cout<<dp[j]<<" ";
        // }
        // cout<<endl;
        cout<<dp[target]<<'\n';
    }
}