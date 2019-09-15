#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int frek[2010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a1,a2,k1,k2;
	cin >> a1 >> a2 >> k1 >> k2;
	if (k1 > k2)
	{
		swap(k1,k2);
		swap(a1,a2);
	}
	// cout << k1 << " " << k2 << endl;
	int n;
	cin >> n;
	int simpan = n;
	int tim1 = min(a1,n / k1);
	n -= tim1 * k1;
	assert(n >= 0);
	int tim2 = min(a2,n / k2);
	n -= tim2 * k2;
	assert(n >= 0);
	int mx = tim1 + tim2;
	n = simpan;
	int tot = ((a1 * (k1 - 1)) + (a2 * (k2 - 1)));
	int mn = max(0,n - tot);
	cout << mn << " " << mx << endl;
}