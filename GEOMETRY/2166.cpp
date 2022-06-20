#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pair<double,double> > v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    double num=0;
    for(int i=0;i<n;i++){
        if(i==n-1){
            num+=v[n-1].first*v[0].second;
            num-=v[0].first*v[n-1].second;
        }else{
            num+=v[i].first*v[i+1].second;
            num-=v[i+1].first*v[i].second;
        }
    }
    num=fabs(num)/(double)2;

    cout<<fixed;
    cout.precision(1);
    cout<<num;
}