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
	int n,k;
	cin >> n >> k;
	int ans = (2 *n) + 1;
	if (k == 1 || k == n)
		ans += n - 1;
	else
		ans += min(k - 1 + k - 1 + n - k,n - k + n - k + k - 1);
	cout << ans << endl;	
}