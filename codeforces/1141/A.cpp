#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin >> n >> m;
	if (m % n != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	ll bagi = m / n;
	ll ans = 0ll;
	while (bagi % 2 == 0)
	{
		bagi /= 2;
		++ans;
	}
	while (bagi % 3 == 0)
	{
		bagi /= 3;
		++ans;
	}
	if (bagi != 1)
		cout << -1 << endl;
	else
		cout << ans << endl;
}