#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>
#include<stack>

using namespace std;

vector<pair<int, int> > v[1001];
priority_queue<pair<int,int> > pq;
int c[1001];
int p[1001] = {-1, };
int n,m,a,b,ac;

void dij(int start){
    c[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int cur=pq.top().second;
        int cur_len=-pq.top().first;
        pq.pop();
        if (c[cur] < cur_len)
            continue;
        for(int i=0;i<v[cur].size();i++){
            int next=v[cur][i].first;
            int next_len=v[cur][i].second + cur_len;
            if(next_len < c[next]){
                c[next]=next_len;
                p[next]=cur;
                pq.push(make_pair(-c[next],next));
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        c[i]=INT_MAX;
    for (int i=0;i<m;i++){
        cin>>a>>b>>ac;
        v[a-1].push_back(make_pair(b-1,ac));
    }
    cin>>a>>b;
    dij(a-1);
    cout<<c[b-1]<<endl;
    stack<int> s;
    int cur=b-1;
    while (cur!=a-1){
        s.push(cur);
        cur=p[cur];
    }
    cout<<s.size()+1<<endl;
    cout<<a;
    while (!s.empty()){
        cout<<" "<<s.top()+1;
        s.pop();
    }

}