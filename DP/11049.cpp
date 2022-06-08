#include<iostream>
#include<algorithm>

using namespace std;

long long mul[501][501];
int mat[501][2];
int n;

long long aaa(int a, int b){
    if(b-a==1){
        mul[a][b]=mat[a][0]*mat[a][1]*mat[a+1][1];
        return mul[a][b];
    }
    if(mul[a][b]!=999999999999){
        return mul[a][b];
    }
    for(int i=a;i<b;i++){
        long long temp=mat[a][0]*mat[i][1]*mat[b][1];
        mul[a][b]=min(mul[a][b],temp+aaa(a,i)+aaa(i+1,b));
    }
    return mul[a][b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>mat[i][0]>>mat[i][1];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mul[i][j]=999999999999;
            if(i==j)
                mul[i][j]=0;
        }
    }
    cout<<aaa(0,n-1);
}