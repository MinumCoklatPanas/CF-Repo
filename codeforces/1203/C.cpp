#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

ll tab[400010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	ll ans = tab[1];
	for (int i = 1 ; i <= n ; i++)
		ans = __gcd(ans,tab[i]);
	ll cnt = 0ll;
	for (ll i = 1 ; i * i <= ans ; i++) if (ans % i == 0)
	{
		if (i * i == ans)
			++cnt;
		else
			cnt += 2;
	}
	cout << cnt << endl;
}