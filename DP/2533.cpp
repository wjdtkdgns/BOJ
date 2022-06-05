#include<iostream>
#include<vector>

using namespace std;

int n;
bool early[1000001]={0, }, visited[1000001]={0, };
vector<int> v[1000001];

void postfix(int past, int cur){
    visited[cur]=1;
    if(v[cur].size()==0){
        early[cur]=1;
        return;
    }
    if(v[cur].size()==1){
        early[past]=1;
        return;
    }
    for(int i=0;i<v[cur].size();i++){
        if(!visited[v[cur][i]]){
            postfix(cur,v[cur][i]);
        }
    }
    if(early[cur]==1){
        return;
    }
    else{
        for(int i=0;i<v[cur].size();i++){
            if(v[cur][i]!=past && early[v[cur][i]]==0){
                early[cur]=1;
            }
        }
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if(n==2){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            postfix(0,i);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(early[i]==1){
            cnt++;
        }
    }
    cout<<cnt;
}