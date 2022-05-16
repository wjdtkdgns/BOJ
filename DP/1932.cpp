#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> origin[501];
vector<long long> v[501];

void DP(int depth,int idx){
    if (v[depth+1][idx]<origin[depth+1][idx]+v[depth][idx])
    {
        v[depth+1][idx] = origin[depth+1][idx]+v[depth][idx];
    }
    if (v[depth+1][idx+1]<origin[depth+1][idx+1]+v[depth][idx])
    {
        v[depth+1][idx+1] = origin[depth+1][idx+1]+v[depth][idx];
    }
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        for(int j=0;j<=i;j++){
            cin>>a;
            v[i].push_back(a);
            origin[i].push_back(a);
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            DP(i,j);
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if(max<v[n-1][i])
            max=v[n-1][i];
    }
    cout<<max;
}