#include<iostream>
#include<algorithm>

using namespace std;

pair<int, long long> dp[501][501];
int p[501];

int recur(int start, int end){
    if(dp[start][end].first!=99999999){
        return dp[start][end].first;
    }
    if(start==end){
        dp[start][start].second=0;
        return p[start];
    }
    for(int i=start;i<end;i++){
        int temp = recur(start,i)+recur(i+1,end);
        long long ac = dp[start][i].second + dp[i+1][end].second;
        if(temp+ac<dp[start][end].second){
            dp[start][end].first=temp;
            dp[start][end].second=temp+ac;
        }
    }
    return dp[start][end].first;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int K;
        cin>>K;
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                dp[i][j]=make_pair(99999999,99999999999);
            }
        }
        for(int i=0;i<K;i++){
            cin>>p[i];
        }
        int a = recur(0,K-1);
        cout<<dp[0][K-1].second<<'\n';
    }
}