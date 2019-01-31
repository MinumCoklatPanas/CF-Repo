#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 300010;
const int MOD = 1e9 + 7;

ll tab[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	sort(tab + 1,tab + n + 1);
	ll ans = 0ll;
	int r = n;
	for (int i = 1 ; 2 * i <= n ; i++)
	{
		ll tmp = tab[i] + tab[r--];
		ans += tmp * tmp;
	}
	cout << ans << endl;
}