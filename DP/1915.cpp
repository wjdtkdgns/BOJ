#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

// int는 1000자리 숫자 못받아서 string 사용함

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    int s[1000][1000]={0,};
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        for(int j=0;j<m;j++){
            s[j][i]=a[j]-'0';
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(s[j][i]==1)
                s[j][i]=min(s[j][i-1],min(s[j-1][i-1],s[j-1][i]))+1;
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(max<s[j][i])
                max=s[j][i];
        }
    }
    cout<<max*max;   
}
