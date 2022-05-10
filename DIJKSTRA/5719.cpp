#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 중복되는 곳을 찾아야한다. 아니면 시간초과 바로 뜬다.

typedef pair<int, int> p;

vector<p> V[501];
vector<int> parent[501];
int N, M, S, D, d[501];


void djikstra_check(int start)
{
    priority_queue<p> pq;
	d[start] = 0;
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int current = pq.top().first;
		int time = -pq.top().second;
		pq.pop();
		if (d[current] < time)
			continue;
		for (int i = 0; i < V[current].size(); i++)
		{
			int next = V[current][i].first;
			int nexttime = V[current][i].second;
			if (d[next] > nexttime + time)
			{
                parent[next].clear();
                parent[next].push_back(current);
				d[next] = nexttime + time;
				pq.push(make_pair(next, -d[next]));
			}
            else if (d[next] == nexttime + time)
                parent[next].push_back(current);
		}
	}
}

void clear_quickest(int cur){
    if (cur == S)
        return;
    for(int i=0;i<parent[cur].size();i++){
        int past = parent[cur][i];
        int j=0;
        while(V[past][j].first!=cur)
            j++;
        if (V[past][j].second == -1)
            continue;
        V[past][j].second = -1;
        clear_quickest(past);
    }
}

void djikstra(int start)
{
    priority_queue<p> pq;
	d[start] = 0;
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int current = pq.top().first;
		int time = -pq.top().second;
		pq.pop();
		if (d[current] < time)
			continue;
		for (int i = 0; i < V[current].size(); i++)
		{
			int next = V[current][i].first;
			int nexttime = V[current][i].second;
            if (nexttime == -1)
                continue;
			if (d[next] > nexttime + time)
			{
				d[next] = nexttime + time;
				pq.push(make_pair(next, -d[next]));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		cin >> S >> D;
		for (int i = 0; i < N; i++)
		{
			V[i].clear();
			parent[i].clear();
			d[i] = INT_MAX;
		}
		int a, b, c;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			V[a].push_back(make_pair(b,c));
		}

        djikstra_check(S);
        if (d[D] == INT_MAX){
            cout<<"-1"<<endl;
            continue;
        }
        clear_quickest(D);
		for (int i = 0; i < N; i++)
			d[i] = INT_MAX;
		djikstra(S);

		if (d[D] != INT_MAX)
			cout << d[D] << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}