#include<iostream>
#include<vector>

using namespace std;

int n;
int num[100];
vector<pair<int,long long> > v[100];

int only(int a, int b, int op){
    int temp;
    if(op==1){
        temp = v[a][b].first+num[a+1];
    }
    else{
        temp = v[a][b].first-num[a+1];
    }
    for(int i=0;i<v[a+1].size();i++){
        if(v[a+1][i].first==temp)
            return i;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    v[0].push_back(make_pair(num[0],1));
    for(int i=1;i<n-1;i++){
        for(int j=0;j<v[i-1].size();j++){
            if(v[i-1][j].first+num[i]<=20){
                int a = only(i-1, j, 1);
                if(a==-1){
                    v[i].push_back(make_pair(v[i-1][j].first+num[i],v[i-1][j].second));
                }
                else{
                    v[i][a].second+=v[i-1][j].second;
                }
            }
            if(v[i-1][j].first-num[i]>=0){
                int a = only(i-1, j, 0);
                if(a==-1){
                    v[i].push_back(make_pair(v[i-1][j].first-num[i],v[i-1][j].second));
                }
                else{
                    v[i][a].second+=v[i-1][j].second;
                }
            }
        }
    }
    long long ans=0;
    for(int i=0;i<v[n-2].size();i++){
        if(v[n-2][i].first==num[n-1])
            ans+=v[n-2][i].second;
    }
    cout<<ans;
}