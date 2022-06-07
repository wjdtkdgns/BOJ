#include<iostream>
#include<vector>

using namespace std;

// 앞에서부터 비교하지않고
// 한 지점에서 퍼져나가면서 비교

int n,m,b[100001];
vector<bool> v[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j){
                v[i].push_back(1);
                continue;
            }
            if(j==i+1 && b[i]==b[j]){
                v[i].push_back(1);
                continue;
            }
            v[i].push_back(0);
        }
    }
    for(int i=1;i<=n;i++){
        int start=i-1;
        int end=i+1;
        while(start>0 && end<=n){
            if(v[start+1][end-start-2] && b[start]==b[end])
                v[start][end-start]=1;
            start--;
            end++;
        }
    }
    for(int i=1;i<=n;i++){
        int start=i-1;
        int end=i+2;
        while(start>0 && end<=n){
            if(v[start+1][end-start-2] && b[start]==b[end])
                v[start][end-start]=1;
            start--;
            end++;
        }
    }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=n-i;j++){
    //         cout<<v[i][j];
    //     }
    //     cout<<endl;
    // }
    cin>>m;
    for(int q=0;q<m;q++){
        int a,b;
        cin>>a>>b;
        cout<<v[a][b-a]<<'\n';
    }
}