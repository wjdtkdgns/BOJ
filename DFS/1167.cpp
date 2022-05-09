#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

// vector 중첩보단 vector하나를 선언할 때 vector array로 만드는게 더 좋음

int V;
int max_len=0, max_node=0;
bool visited[100001] = {0, };
vector<pair<int,int> > vec[100001];

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
    for(int i=0;i<V;i++){
        cin >> from;
        cin >> to;
        while (to != -1){
            cin >> len;
            vec[from - 1].push_back(make_pair(to - 1, len));
            cin >> to;
        }
    }
    DFS(0, 0);
    for(int i=0; i<V; i++)
        visited[i] = 0;
    DFS(max_node, 0);
    cout << max_len;
}

// 5
// 1 3 2 -1
// 4 2 4 3 3 5 6 -1
// 3 1 2 4 3 -1
// 2 4 4 -1
// 5 4 6 -1