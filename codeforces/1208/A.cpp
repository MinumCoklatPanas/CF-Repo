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
		ll a,b,n;
		cin >> a >> b >> n;
		n %= 3;
		if (n == 0)
			cout << a << endl;
		else
		if (n == 1)
			cout << b << endl;
		else
			cout << (a ^ b) << endl;
	}
}