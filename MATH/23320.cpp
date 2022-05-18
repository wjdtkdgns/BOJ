#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, m[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m[i];
    }
    int p, min;
    cin>>p>>min;
    int cnt=0;
    int i;
    for(i=0;i<n;i++)
        if(m[i]>=min)
            cnt++;
    int cnt2=0;
    int j;
    for(j=0;j<n;j++)
        if(j>=n-n*p/100)
            cnt2++;
    cout<<cnt2<<" "<<cnt;
}