#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> tab[100010];
bool vis[100010];
pair<ll,ll> price[100010];

void dfs(ll x)
{
	vis[x]=1;
//	cout<<x<<" x\n";
	for (ll i=0;i<tab[x].size();i++)
	{
		if (vis[tab[x][i]]) continue;
		dfs(tab[x][i]);
	}
	return;
}

int main()
{
	ll n,m;
	cin>>n>>m;
	for (ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		price[i]={a,i};
	}
	for (ll i=1;i<=m;i++)
	{
		ll a,b;
		cin>>a>>b;
		tab[a].push_back(b);
		tab[b].push_back(a);
	}
	sort(price+1,price+n+1);
	memset(vis,0,sizeof(vis));
	ll ans=0;
	for (ll i=1;i<=n;i++)
	{
		if (vis[price[i].second]) continue;
		ans+=price[i].first;
		dfs(price[i].second);
	}
	cout<<ans<<"\n";
}
