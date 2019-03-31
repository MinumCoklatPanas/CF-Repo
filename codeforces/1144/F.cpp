#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

vector< pair<int,int> > adj[200010];
pair<int,int> edge[200010];
int color[200010];
bool state[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(color,-1,sizeof(color));
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> edge[i].first >> edge[i].second;
		adj[edge[i].first].push_back(make_pair(edge[i].second,i));
		adj[edge[i].second].push_back(make_pair(edge[i].first,i));
	}
	queue<int> q;
	q.push(1);
	color[1] = 1;
	while (!q.empty())
	{
		int depan = q.front();
		q.pop();
		for (int i = 0 ; i < adj[depan].size() ; i++)
		{
			if (color[adj[depan][i].first] == -1)
			{
				color[adj[depan][i].first] = 1 - color[depan];
				q.push(adj[depan][i].first);
			}
			else
			if (color[adj[depan][i].first] == color[depan])
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	//1 u -> v 0 v -> u
	for (int i = 1 ; i <= m ; i++)
	{
		cout << color[edge[i].first];
	}
	cout << endl;
}