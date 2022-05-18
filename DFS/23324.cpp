#include<iostream>
#include<climits>
#include<vector>

using namespace std;

// 문제를 잘 읽자!!

bool visited[100001]={0, }, visited2[100001]={0, };
vector<pair<int, int> > v[100002];
long long cnt=0, cnt2=0;

void dfs(int cur){
    visited[cur]=1;
    // cout<<cur<<endl;
    cnt++;
    for(int i=0;i<v[cur].size();i++){
        if(!v[cur][i].second&&!visited[v[cur][i].first]){
            dfs(v[cur][i].first);
        }
    }
    // cout<<endl;
}

void dfs2(int cur){
    visited2[cur]=1;
    cnt2++;
    for(int i=0;i<v[cur].size();i++){
        if(!v[cur][i].second&&!visited2[v[cur][i].first])
            dfs2(v[cur][i].first);
    }
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int v1,v2;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(i==k-1){
            v[a-1].push_back(make_pair(b-1, 1));
            v[b-1].push_back(make_pair(a-1, 1));
            v1=a-1;
            v2=b-1;
        }
        else{
            v[a-1].push_back(make_pair(b-1, 0));
            v[b-1].push_back(make_pair(a-1, 0));
        }
    }
    dfs(v1);
    if (visited[v2]==1){
        cout<<0;
        return 0;
    }
    dfs2(v2);
    cout<<cnt*cnt2;

    return 0;
}