#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
 
typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
 
ll tab[100010];
vector<ll> adj[100010];
ll cnt[110];
ll ans = INFF;

ll readInt ()
{
    bool minus = false;
    ll result = 0;
    char ch;
    ch = _getchar_nolock();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = _getchar_nolock();
    }
    if (ch == '-') minus = true;
    else result = ch-'0';
    while (true)
    {
        ch = _getchar_nolock();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}
 
ll bfs(int start,int sz)
{
    vector<int> dist(sz + 5,INF);
    vector<bool> vis(sz + 5,false);
    vector<int> papa(sz + 5,-1);
    queue< int > q;
    dist[start] = 0;
    q.push(start);
    vis[start] = 1;
    int ans = INF;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur])
        {
            if (dist[it] > dist[cur] + 1)
            {
                assert(!vis[it]);
                vis[it] = 1;
                papa[it] = cur;
                dist[it] = dist[cur] + 1;
                q.push(it);
            }
            else
            if (papa[it] != cur && papa[cur] != it)
                ans = min(ans,dist[it] + dist[cur] + 1);
        }
    }
    return ans;
}
 
int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	ll n = readInt();
	// cin >> n;
    vector<ll> considered;
	for (ll i = 1 ; i <= n ; i++)
	{
		// cin >> tab[i];
		tab[i] = readInt();
		for (ll j = 0 ; j < 64 ; j++)
		{
			if (tab[i] & (1ll << j))
				++cnt[j];
		}
        if (tab[i]) considered.push_back(tab[i]);
	}
	for (ll i = 0 ; i < 64 ; i++)
	{
		if (cnt[i] > 2)
		{
			puts("3");
			// cout << 3 << endl;
			return 0;
		}
	}
    // cout << considered.size() << endl;
	for (ll i = 0 ; i < considered.size() ; i++)
	{
		for (ll j = i + 1 ; j < considered.size() ; j++)
		{
			if (considered[i] & considered[j])
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
    ll ans = INF;
	for (ll i = 0 ; i < considered.size() ; i++)
	{
        ans = min(ans,bfs(i,considered.size()));
	}
	if (ans == INF)
		ans = -1;
	printf("%lld\n",ans);
	// cout << ans << endl;
}