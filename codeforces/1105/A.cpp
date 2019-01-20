#include <bits/stdc++.h>
using namespace std;

int tab[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int t = -1;
	int ans = 1e9;
	for (int i = 1 ; i <= 101 ; i++)
	{
		int cost = 0;
		int kiri = i - 1;
		int now = i;
		int kanan = i + 1;
		for (int j = 1 ; j <= n ; j++)
		{
			int mn = min(abs(tab[j] - kiri),abs(tab[j] - now));
			mn = min(mn,abs(tab[j] - kanan));
			cost += mn;
		}
		if (cost < ans)
		{
			ans = cost;
			t = now;
		}
	}
	cout << t << " " << ans << endl;
}