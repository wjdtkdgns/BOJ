#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//n^2가 아니라 nlog(n)으로 해결가능함
// lowerbound ==> log(n)

int main(){
    int n, a[1000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(v.size()==idx)
            v.push_back(a[i]);
        else
            v[idx]=a[i];
    }
    cout<<v.size();
}