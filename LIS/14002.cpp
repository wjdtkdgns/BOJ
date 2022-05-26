#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num[1001], order[1001];
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        int a=lower_bound(v.begin(),v.end(),num[i])-v.begin();
        if(a==v.size()){
            // cout<<a<<' '<<num[i]<<endl;
            v.push_back(num[i]);
        }
        else{
            v[a]=num[i];
        }
        order[i]=a;
    }
    cout<<v.size()<<'\n';
    int cur=v.size()-1;
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        // cout<<order[i];
        if(cur==order[i]){
            s.push(num[i]);
            cur--;
        }
        if(cur==-1)
            break;
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}