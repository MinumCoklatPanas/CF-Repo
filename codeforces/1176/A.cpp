#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll cnt = 0;
		while (n != 1)
		{
			if (n % 5 == 0)
				n = 4 * (n / 5);
			else
			if (n % 3 == 0)
				n = 2 * (n / 3);
			else
			if (n % 2 == 0)
				n = n / 2;
			else
				break;
			++cnt;
		}
		if (n == 1)
			cout << cnt << endl;
		else
			cout << -1 << endl;
	}
}