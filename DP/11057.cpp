#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n ,up[10]={10,9,8,7,6,5,4,3,2,1};
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=8;j>=0;j--){
            up[j]=up[j]+up[j+1];
            if(up[j]>=10007)
                up[j]%=10007;
        }
    }
    cout<<up[0];
}