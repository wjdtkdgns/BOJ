#include<iostream>

using namespace std;

// knapsnak standard

int n, k;
int w[101],v[101],a[101][100001]={0,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(w[i]<=j){
                if(v[i]+a[i-1][j-w[i]]>a[i-1][j])
                    a[i][j]=v[i]+a[i-1][j-w[i]];
                else
                    a[i][j]=a[i-1][j];
            }
            else{
                a[i][j]=a[i-1][j];
            }
        }
    }
    cout<<a[n][k];
}