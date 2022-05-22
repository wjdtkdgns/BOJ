#include<iostream>
#include<queue>
#include<climits>
#include<cstring>

using namespace std;

int visited[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(visited,10000,sizeof(visited));
    int n,k;
    cin>>n>>k;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,n));
    while(!pq.empty()){
        int cur=pq.top().second;
        int time=-pq.top().first;
        visited[cur]=time;
        pq.pop();
        if(cur == k){
            cout<<time;
            break;
        }
        if(cur*2<=100000&&visited[cur*2]>time)
            pq.push(make_pair(-time, cur*2));
        if(cur+1<=100000&&visited[cur+1]>time+1)
            pq.push(make_pair(-(time+1),cur+1));
        if(cur-1>=0&&visited[cur-1]>time+1)
            pq.push(make_pair(-(time+1),cur-1));
    }
}