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

bool ada[8010];
int tab[8010];
int cnt[8010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			ada[i] = 0;
			cnt[i] = 0;
			cin >> tab[i];
		}
		for (int i = 1 ; i <= n ; i++)
			cnt[tab[i]]++;
		int ans = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			int cur = tab[i];
			for (int j = i + 1 ; j <= n ; j++)
			{
				cur += tab[j];
				if (cur > n) break;
				if (cnt[cur])
				{
					ada[cur] = 1;
				}
			}
		}
		for (int i = 1 ; i <= n ; i++)
			ans += ada[i] * cnt[i];
		cout << ans << endl;
	}
	return 0;
}