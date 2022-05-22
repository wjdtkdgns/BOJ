#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,p[100001];
    vector<int> v[100001];
    bool visited[100001]={0, };

    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int, int> > q;
    q.push(make_pair(0,1));
    while(!q.empty()){
        int parent=q.front().first;
        int cur=q.front().second;
        q.pop();
        visited[cur]=1;
        p[cur]=parent;
        for(int i=0;i<v[cur].size();i++){
            if(!visited[v[cur][i]])
                q.push(make_pair(cur,v[cur][i]));
        }
    }
    for(int i=2;i<=n;i++)
        cout<<p[i]<<'\n';
}