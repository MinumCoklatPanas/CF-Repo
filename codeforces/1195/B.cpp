#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool DP[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin >> n >> k;
	ll D = 9 + 8 * (n + k);
	// cout << D << endl;
	D = (ll)sqrt(D);
	ll taruh = (-3 + D) / 2;
	ll ans = n - taruh;
	cout << ans << endl;
}