#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long li[100000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>li[i];
    }
    long long ansgap = 2000000001;
    int start=0, last=n-1, ansstart, anslast;
    while(start!=last){
        if(labs(li[last]+li[start])<ansgap){
            ansstart=li[start];
            anslast=li[last];
            ansgap=labs(li[last]+li[start]);
        }
        if(labs(li[start])<labs(li[last])){
            last--;
        }else{
            start++;
        }
    }
    cout<<ansstart<<" "<<anslast;
}