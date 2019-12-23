#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int tab[5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> tab[1] >> tab[2] >> tab[3];
	int ans = 0;
	for (int i = 3 ; i <= 100 ; i++) {
		if ((tab[1] >= i - 2) && (tab[2] >= i - 1) && (tab[3] >= i)) {
			// cout << i << endl;
			ans = 3 * i - 3;
		}
	}
	cout << ans << endl;
}