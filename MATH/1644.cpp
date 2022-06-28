#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    if(n==1){
        cout<<"0";
        return 0;
    }

    bool prime[4000002]={0, };
    for(int i=2;i<=n;i++){
        prime[i]=1;
    }
    for(int i=2;i<n;i++){
        if(prime[i]==0){
            continue;
        }
        for(int j=2;j*i<=n;j++){
            prime[j*i]=0;
        }
    }
    int start=1, end=2, ac=2, cnt=0;
    while(start<=end){
        // cout<<start<<" "<<end<<" "<<ac<<endl;

        if(ac==n&&prime[start]&&prime[end]){
            cnt++;
            start++;
            if(prime[start-1]){
                ac-=start-1;
            }
        }
        else if(ac<n&&end!=n){
            end++;
            if(prime[end]){
                ac+=end;
            }
        }
        else{
            start++;
            if(prime[start-1]){
                ac-=start-1;
            }
        }
    }
    cout<<cnt;
}

// 2
// 3
// 5
// 7
// 11
// 13
// 17
// 19
// 23
// 29
// 31
// 37