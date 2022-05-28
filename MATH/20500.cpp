#include<iostream>

using namespace std;

// 노가다는 컴퓨터 시키자

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if(n<2){
        cout<<0;
        return 0;
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        if(i==2){
            ans=1;
            continue;
        }
        if(i%2==0){
            ans = ans*2 + 1;
        }
        else{
            ans = ans*2 - 1;
        }
        ans%=1000000007;
    }
    cout<<ans;

}