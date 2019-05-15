#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int par[500010];
int frek[500010];

int finds(int x)
{
	return (par[x] == x ? x : par[x] = finds(par[x]));
}

void join(int x,int y)
{
	int px = finds(x);
	int py = finds(y);
	if (px == py) return;
	par[px] = py;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1 ; i <= 500000 ; i++)
		par[i] = i;
	int n,m;
	cin >> n >> m;
	for (int i = 1 ; i <= m ; i++)
	{
		int k;
		cin >> k;
		if (!k) continue;
		int lead;
		cin >> lead;
		for (int j = 1 ; j < k ; j++)
		{
			int ta;
			cin >> ta;
			join(lead,ta);
		}	
	}
	for (int i = 1 ; i <= n ; i++)
		frek[finds(i)]++;
	for (int i = 1 ; i <= n ; i++)
	{
		if (i == n)
			cout << frek[finds(i)] << endl;
		else
			cout << frek[finds(i)] << " ";
	}
}