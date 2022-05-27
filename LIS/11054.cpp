#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s[1001], inc[1001], dec[1001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<int> v;
    for(int i=0;i<n;i++){
        int idx=lower_bound(v.begin(),v.end(),s[i])-v.begin();
        inc[i]=idx+1;
        if(v.size()==idx)
            v.push_back(s[i]);
        else
            v[idx]=s[i];
    }
    v.clear();
    for(int i=n-1;i>=0;i--){
        int idx=lower_bound(v.begin(),v.end(),s[i])-v.begin();
        dec[i]=idx+1;
        if(v.size()==idx)
            v.push_back(s[i]);
        else
            v[idx]=s[i];
    }
    int max=-1000000000;
    for(int i=0;i<n;i++){
            // cout<<inc[i]<<" "<<dec[i]<<endl;
        if(max<inc[i]+dec[i]){
            max=inc[i]+dec[i];
        }
    }
    cout<<max-1;
}