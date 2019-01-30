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
	int q;
	cin >> q;
	while (q--)
	{
		ll k,x;
		cin >> k >> x;
		ll c = x - 9;
		ll ans = 9 * k + c;
		cout << ans << endl;
	}
}