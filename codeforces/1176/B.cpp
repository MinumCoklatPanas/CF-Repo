#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int cnt[5];

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
		memset(cnt,0,sizeof(cnt));
		for (int i = 1 ; i <= n ; i++)
		{
			int ta;
			cin >> ta;
			cnt[ta % 3]++;
		}
		int ans = cnt[0];
		int mn = min(cnt[1],cnt[2]);
		ans += mn;
		cnt[1] -= mn;
		cnt[2] -= mn;
		ans += cnt[1] / 3;
		ans += cnt[2] / 3;
		cout << ans << endl;
	}
}