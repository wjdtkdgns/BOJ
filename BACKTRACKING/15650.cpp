#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,num[9]={0,1,2,3,4,5,6,7,8};
    cin>>n>>m;
    int change=m;
    while(1){
        for(int i=1;i<=m;i++){
            cout<<num[i];
            if(i!=m)
                cout<<" "; 
        }
        if(num[1]==n-m+1)
            break;
        num[change]++;
        if(num[change]>n){
            while(num[change]>=n-m+change)
                change--;
            num[change]++;
            while(change!=m){
                num[change+1]=num[change]+1;
                change++;
            }
        }
        cout<<endl;
    }
}