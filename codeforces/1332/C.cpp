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

// int frek[30][200010];
char tab[200010];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
		}
		int ans = 0;
		int l = 1;
		int r = k;
		while (l < r)
		{
			map<char,int> frek;
			int curL = l;
			int curR = r;
			for (int i = 1 ; i <= n / k ; i++) 
			{
				frek[tab[curL]]++;
				frek[tab[curR]]++;
				curL += k;
				curR += k;
			}
			int mx = 0;
			for (auto it : frek)
				mx = max(mx,it.second);
			int ganti = (2 * (n / k)) - mx;
			ans += ganti;
			// cout << l << " " << r << " " << ganti << endl;
			++l; --r;
		}
		if (l == r)
		{
			map<char,int> frek;
			int cur = l;
			for (int i = 1 ; i <= n / k ; i++)
			{
				frek[tab[cur]]++;
				cur += k;
			}
			int mx = 0;
			for (auto it : frek)
				mx = max(mx,it.second);
			ans += n / k - mx;
		}
		cout << ans << endl;
	}
	return 0;
}