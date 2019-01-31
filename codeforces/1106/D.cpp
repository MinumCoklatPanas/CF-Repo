#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 100010;
const int MOD = 1e9 + 7;

vector< int > adj[MAXN];
bool sudah[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	priority_queue< int > pq;
	pq.push(-1);
	vector< int > ans;
	while (!pq.empty())
	{
		int now = -pq.top();
		sudah[now] = 1;
		ans.push_back(now);
		pq.pop();
		for (int i = 0 ; i < adj[now].size() ; i++)
		{
			if (!sudah[adj[now][i]])
			{
				pq.push(-adj[now][i]);
				sudah[adj[now][i]] = 1;
			}
		}
	}
	for (int i = 0 ; i < n ; i++)
		cout << ans[i] << " ";
	cout << endl;
}