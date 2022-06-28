#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

// 2개를 확정해놓은 상태에서 찾지말고, 기준점 1개 정해두고 나머지 2개 찾기

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
    sort(li, li+n);
    long long ansgap = 4000000001;
    int last, mid, ansstart, anslast, ansmid;
    for(int start=0;start<n-2;start++){
        mid = start+1;
        last = n-1;
        while(mid!=last){
            // cout<<mid<<" "<<last<<endl;
            if(labs(li[last]+li[start]+li[mid])<ansgap){
                ansstart=li[start];
                anslast=li[last];
                ansmid=li[mid];
                ansgap=labs(li[last]+li[start]+li[mid]);
                // cout<<"         "<<li[start]<<" "<<li[mid]<<" "<<li[last]<<" "<<ansgap<<endl;
            }
            if(li[last]+li[start]+li[mid]>0){
                last--;
            }else{
                mid++;
            }
        }
    }
    cout<<ansstart<<" "<<ansmid<<" "<<anslast;
}

// -97 -6 -2 6 98

// -24 -6 -3 -2 61 98 100