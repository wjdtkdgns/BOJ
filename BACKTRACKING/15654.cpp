#include<iostream>
#include<algorithm>

using namespace std;

// ios_base .... 쓰고 endl 쓰면 시간초과남 

int n,m,num[8]={0, },ans[8]={0,},visited[8]={0,};

void recur(int idx){
    if(idx==m){
        for(int i=0;i<m;i++){
            cout<<ans[i];
            if(i!=m-1)
                cout<<" ";
        }
        cout<<'\n';
        return;
    }
    else{
        for(int i=0;i<n;i++){
            if(visited[i]==1)
                continue;
            visited[i]=1;
            ans[idx]=num[i];
            recur(idx+1);
            visited[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    sort(num,num+n);
    recur(0);
}