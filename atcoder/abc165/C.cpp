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

int n,m,q;
int a[55];
int b[55];
int c[55];
int d[55];

int rec(int ix,int lastDigit,vector< int > &tab)
{
	int ret = 0;
	if (ix == n)
	{
		for (int i = 1 ; i <= q ; i++)
		{
			if (tab[b[i]] - tab[a[i]] == c[i])
				ret += d[i];
		}
		// for (auto it : tab)
		// 	cout << it << " ";
		// cout << ": " << ret;
		// cout << endl;
		return ret;
	}
	for (int i = lastDigit ; i <= m ; i++)
	{
		tab[ix] = i;
		ret = max(ret,rec(ix + 1,i,tab));
	}
	return ret;
}	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1 ; i <= q ; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		--b[i]; --a[i];
	}
	vector< int > tab(n,0);
	int ans = rec(0,1,tab);
	cout << ans << endl;
	return 0;
}