#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, s, num[100001]={0,};
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    long long start=1, end=1, ac=num[1], ans=99999999;
    while(1){
        // cout<<start<<" "<<end<<" "<<ac<<endl;
        if(ac<s){
            if(end==n){
                break;
            }
            end++;
            ac+=num[end];
        }
        else{
            ans=min(ans,end-start+1);
            start++;
            ac-=num[start-1];  
        }
    }
    if(ans==99999999){
        cout<<0;
    }
    else{
        cout<<ans;
    }
}