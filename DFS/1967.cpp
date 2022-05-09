#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

// 한 점에서 DFS로 가장 깊은 또는 길이가 긴 위치에서 DFS를 다시 시작하면 가장 긴 길이 구할 수 있음.

int V;
int max_len=0, max_node=0;
vector<pair<int,int> > vec[10001];
bool visited[10001] = {0, };

void DFS(int node, int len){
    if (max_len < len){
        max_len = len;
        max_node = node;
    }
    visited[node] = 1;
    for (int i=0; i<vec[node].size(); i++){
        if (!visited[vec[node][i].first])
            DFS(vec[node][i].first, len + vec[node][i].second);
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int from, to, len;
    cin >> V;
    for(int i=1;i<V;i++){
        cin >> from;
        cin >> to;
        cin >> len;
        vec[from - 1].push_back(make_pair(to - 1, len));
        vec[to - 1].push_back(make_pair(from - 1, len));
    }
    DFS(0, 0);
    for(int i=0; i<10001; i++)
        visited[i] = 0;
    DFS(max_node, 0);
    cout << max_len;
}