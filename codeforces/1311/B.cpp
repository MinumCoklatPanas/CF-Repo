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

int tab[110];
pair<int,int> sorted[110];
bool ada[110];

bool cek(int l,int r)
{
	bool ret = 1;
	for (int i = l ; i <= r ; i++)
		ret &= ada[i];
	return ret;	
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
		memset(ada,0,sizeof(ada));
		int n,m;
		cin >> n >> m;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			sorted[i] = {tab[i],i};
		}
		for (int i = 1 ; i <= m ; i++)
		{
			int ta;
			cin >> ta;
			ada[ta] = 1;
		}
		sort(sorted + 1,sorted + n + 1);
		bool can = 1;
		for (int i = 1 ; i <= n ; i++) if (sorted[i].second != i)
		{
			can &= cek(min(sorted[i].second,i),max(sorted[i].second,i) - 1);
		}
		if (can)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}