#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a[1001];
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n-1;i>=0;i--){
        int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
        if(v.size()==idx){
            v.push_back(a[i]);
        }
        else{
            v[idx]=a[i];
        }
    }

    cout<<v.size();
}