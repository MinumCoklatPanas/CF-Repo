#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

map<ll,ll> dist;
vector< ll > ans;
vector< ll > pos;
ll n,m;

void bfs()
{
	queue< pair< ll,ll > > q;
	for (ll i = 0 ; i < pos.size() ; i++)
	{
		q.push({pos[i],0});
		dist[pos[i]] = 0;
	}
	while (!q.empty())
	{
		pair<ll,ll> cur = q.front();
		q.pop();
		ll x = cur.first;
		ll step = cur.second;
		if (dist[x] != step) continue;
		if (step != 0)
			ans.push_back(x);
		if (ans.size() == m) return;
		if (!dist.count(x - 1))
		{
			q.push({x - 1,step + 1});
			dist[x - 1] = step + 1;
		}
		else
		if (dist[x - 1] > step + 1)
		{
			q.push({x - 1,step + 1});
			dist[x - 1] = step + 1;
		}

		if (!dist.count(x + 1))
		{
			q.push({x + 1,step + 1});
			dist[x + 1] = step + 1;
		}
		else
		if (dist[x + 1] > step + 1)
		{
			q.push({x + 1,step + 1});
			dist[x + 1] = step + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 1 ; i <= n ; i++)
	{
		ll ta;
		cin >> ta;
		pos.push_back(ta);
	}
	bfs();
	ll tot = 0;
	assert(ans.size() == m);
	for (ll i = 0 ; i < m ; i++)
		tot += dist[ans[i]];
	cout << tot << endl;
	for (ll i = 0 ; i < m ; i++)
	{
		if (i == m - 1)
			cout << ans[i] << endl;
		else
			cout << ans[i] << " ";
	}
}