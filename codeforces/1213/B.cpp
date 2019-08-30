#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[150010];

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
			cin >> tab[i];
		int ans = n;
		int mn = tab[n];
		for (int i = n - 1 ; i >= 1 ; i--)
		{
			// cout << tab[i] << " " << mn << endl;
			if (tab[i] <= mn)
			{
				// cout << i << endl;
				mn = tab[i];
				--ans;
			}
		}
		cout << ans - 1 << endl;
	}
}