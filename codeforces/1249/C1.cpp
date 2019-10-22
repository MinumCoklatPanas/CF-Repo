#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool cek(ll x) {
	while (x) {
		if (x % 3 == 2) return 0;
		x /= 3;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		while (!cek(n))
			++n;
		cout << n << endl;
	}
}