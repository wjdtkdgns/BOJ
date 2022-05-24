#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

// 쉽게 간단하게 생각해보기

int n;
bool visited[20]={0, };
vector<pair<int, int> > v;
long long mx=INT_MAX,my=INT_MAX;

void dfs(int depth,int idx,long long sx,long long sy){
    if(depth == n/2){
        if(pow(mx,2)+pow(my,2)>pow(sx,2)+pow(sy,2)){
            mx=sx;
            my=sy;
        }
        visited[idx]=0;
        return;
    }
    for(int i=idx;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            long long tempx=sx-2*v[i].first;
            long long tempy=sy-2*v[i].second;
            dfs(depth+1,i,tempx,tempy);
            visited[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        mx=INT_MAX;
        my=INT_MAX;
        for(int j=0;j<20;j++)
            visited[j]=0;
        v.clear();

        long long ax=0,ay=0;
        cin>>n;
        for(int j=0;j<n;j++){
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));
            ax+=a;
            ay+=b;
        }
        dfs(0,0,ax,ay);
        cout<<fixed;
        cout.precision(15);
        cout<<sqrt(pow(mx,2)+pow(my,2))<<'\n';
    }
}