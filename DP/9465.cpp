#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

//DFS 안써도 풀림

int t, n, s[100001][2], k[100001][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>s[j][0];
            k[j][0]=-INT_MAX;
        }
        for(int j=0;j<n;j++){
            cin>>s[j][1];
            k[j][1]=-INT_MAX;
        }
        k[0][0]=s[0][0];
        k[0][1]=s[0][1];
        if(n>1){
            k[1][0]=s[0][1]+s[1][0];
            k[1][1]=s[0][0]+s[1][1];
        }
        for(int j=2;j<n;j++){
            k[j][0]=max(k[j-1][1],k[j-2][1])+s[j][0];
            k[j][1]=max(k[j-1][0],k[j-2][0])+s[j][1];
        }
        cout<<max(k[n-1][0],k[n-1][1])<<endl;
    }
}