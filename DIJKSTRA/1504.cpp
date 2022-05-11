#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<climits>

using namespace std;

// 무향 그래프는 vector pushback 양쪽으로 해줘야함. 아니면 단방향 그래프처럼 계산됨

int N, E;
vector<pair<int,int> > v[800];
int v1, v2;
int d[800],d1[800],d2[800];

void dijkstra(int start, int *d){
    priority_queue<pair<int,int> > pq;
    d[start]=0;
    pq.push(make_pair(start, 0));
    while(!pq.empty()){
        int cur = pq.top().first;
        int len = -pq.top().second;
        pq.pop();
        if (d[cur] < len)
            continue;
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int next_len = v[cur][i].second + len;
            if(d[next] > next_len){
                d[next] = next_len;
                pq.push(make_pair(next, -next_len));
            }
        }

    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>N>>E;
    int a, b, c;
    for(int i=0; i<E; i++){
        cin>>a>>b>>c;
        v[a-1].push_back(make_pair(b-1, c));
        v[b-1].push_back(make_pair(a-1, c));
    }
    cin>>v1>>v2;

    for(int i=0; i<N; i++){
        d[i]=INT_MAX;
        d1[i]=INT_MAX;
        d2[i]=INT_MAX;
    }
    
    dijkstra(0, d);
    dijkstra(v1-1, d1);
    dijkstra(v2-1, d2);

    int min1=d[v1-1]+d1[v2-1]+d2[N-1], min2=d[v2-1]+d2[v1-1]+d1[N-1];
    if (d[N-1] == INT_MAX || d1[v2-1] == INT_MAX){
        cout<<"-1";
        return 0;
    }
    cout<<min(min1,min2);
}