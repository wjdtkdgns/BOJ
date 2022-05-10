#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// pq를 이용할 때, 가장 큰 값을 먼저 이용하고싶으면, -로 바꿔서 집어넣으면 됨.

typedef pair<int, int> p;

vector<p> V[1002];
priority_queue<p> pq;
int	N, M, department, arrival, ac_time[1002];

void djikstra(int start)
{
	ac_time[start] = 0;
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int current = pq.top().first;
		int time = -pq.top().second;
		pq.pop();
		if (ac_time[current] < time)
			continue;
		for (int i = 0; i < V[current].size(); i++)
		{
			int next = V[current][i].first;
			int nexttime = V[current][i].second + time;
			if (ac_time[next] > nexttime)
			{
				ac_time[next] = nexttime;
				pq.push(make_pair(next, -ac_time[next]));
			}
			
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		V[a].push_back(make_pair(b,c));
	}
	cin >> department >> arrival;

	for (int i = 1; i <= N; i++)
		ac_time[i] = INT_MAX;

	djikstra(department);
	cout << ac_time[arrival];
	return 0;
}