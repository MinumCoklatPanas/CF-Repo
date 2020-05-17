#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

bool vis[1010];
int nxt[1010];
int n;

bool cek(int u,int cnt)
{
	if (cnt == n) return 1;
	vis[u] = 1;
	for (int i = 2 ; i <= 4 ; i++)
	{
		if (u + i <= n && !vis[u + i])
		{
			if (cek(u + i,cnt + 1))
			{
				nxt[u] = u + i;
				return 1;
			}
		}
		if (u - i >= 1 && !vis[u - i])
		{
			if (cek(u - i,cnt + 1))
			{
				nxt[u] = u - i;
				return 1;
			}
		}
	}
	return 0;
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
		vector< int > ans;
		cin >> n;
		memset(nxt,-1,sizeof(nxt));
		for (int i = 1 ; i <= n ; i++)
		{
			memset(vis,0,sizeof(vis));
			if (cek(i,1))
			{
				int cur = i;
				while (cur != -1)
				{
					ans.push_back(cur);
					cur = nxt[cur];
				}
				// cout << i << endl;
				break;
			}
		}
		if (ans.size() == 0)
			cout << -1 << endl;
		else
		{
			for (auto it : ans)
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}