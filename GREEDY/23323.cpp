#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    long long n,m;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        long long cnt=0;
        while(n>0){
            cnt++;
            n = n >> 1;
        }
        cout<<cnt+m<<endl;
    }
}