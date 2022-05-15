#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 임의의 점에서 시작이므로, node1에서 시작하지않는 테케가 들어왔을 때, node[1]=0이면 답이 다르게 나옴.

int TC,N,M,W;
vector<pair<pair<int,int>,int> > v;

bool BMF(){
    vector<long long>node(N+1,INT_MAX);
    // node[1]=0;
    int f,t,l;
    for(int i=1;i<N;i++){
        for(int j=0;j<v.size();j++){
            f=v[j].first.first;
            t=v[j].first.second;
            l=v[j].second;
            if(node[t]>node[f]+l)
                node[t]=node[f]+l;
        }
    }
    for(int i=0;i<v.size();i++){
        f=v[i].first.first;
        t=v[i].first.second;
        l=v[i].second;
        if(node[t]>node[f]+l)
            return true;
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>TC;
    for(int i=0;i<TC;i++){
        cin>>N>>M>>W;
        int a,b,c;
        v.clear();

        for(int j=0;j<M;j++){
            cin>>a>>b>>c;
            v.push_back(make_pair(make_pair(a,b),c));
            v.push_back(make_pair(make_pair(b,a),c));
        }
        for(int j=0;j<W;j++){
            cin>>a>>b>>c;
            v.push_back(make_pair(make_pair(a,b),-c));
        }

        if(BMF())
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}