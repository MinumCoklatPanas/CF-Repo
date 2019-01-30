#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 100000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll s,a,b,c;
		cin >> s >> a >> b >> c;
		ll beli = s / c;
		ll bonus = (beli / a) * b;
		ll ans = beli + bonus;
		cout << ans << endl;
	}
}