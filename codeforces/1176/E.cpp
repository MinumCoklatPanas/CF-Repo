#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

vector<int> adj[200010];
int color[200010];

void dfs(int u,int col)
{
	color[u] = col;
	for (int i = 0 ; i < adj[u].size() ; i++)
	{
		if (color[adj[u][i]] == -1)
		{
			dfs(adj[u][i],1 - col);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n,m;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++)
		{
			color[i] = -1;
			adj[i].clear();
		}
		for (int i = 1 ; i <= m ; i++)
		{
			int maudy,ayunda;
			cin >> maudy >> ayunda;
			adj[maudy].push_back(ayunda);
			adj[ayunda].push_back(maudy);
		}
		dfs(1,1);
		vector<int> hitam,putih;
		for (int i = 1 ; i <= n ; i++)
		{
			if (color[i] == 0)
				hitam.push_back(i);
			else
				putih.push_back(i);
		}
		if (hitam.size() > (n / 2))
		{
			cout << putih.size() << endl;
			for (int i = 0 ; i < putih.size() ; i++)
			{
				if (i == putih.size() - 1)
					cout << putih[i] << endl;
				else
					 cout << putih[i] << " ";
			}
		}
		else
		{
			cout << hitam.size() << endl;
			for (int i = 0 ; i < hitam.size() ; i++)
			{
				if (i == hitam.size() - 1)
					cout << hitam[i] << endl;
				else
					 cout << hitam[i] << " ";
			}	
		}
	}
}