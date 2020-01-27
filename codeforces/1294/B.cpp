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

pair<int,int> tab[1010];

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
			cin >> tab[i].first >> tab[i].second;
		sort(tab + 1,tab + n + 1);
		bool cek = 1;
		for (int i = 2 ; i <= n ; i++)
			if (tab[i].second < tab[i - 1].second)
			{
				cek = 0;
				break;
			}
		if (!cek)
			cout << "NO\n";
		else
		{
			cout << "YES\n";
			int curX = 0;
			int curY = 0;
			string ans;
			ans = "";
			for (int i = 1 ; i <= n ; i++)
			{
				for (int j = 1 ; j <= tab[i].first - curX ; j++)
					ans += 'R';
				for (int j = 1 ; j <= tab[i].second - curY ; j++)
					ans += 'U';
				curX = tab[i].first;;
				curY = tab[i].second;
			}
			cout << ans << endl;
		}
	}
	return 0;
}