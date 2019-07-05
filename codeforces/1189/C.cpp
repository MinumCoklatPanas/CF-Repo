#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[100010];
int pref[100010];

int sum(int l,int r)
{
	return pref[r] - pref[l - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		pref[i] = pref[i - 1] + tab[i];
	}
	int q;
	cin >> q;
	while (q--)
	{
		int l,r;
		cin >> l >> r;
		int jarak = (r - l + 1);
		jarak /= 2;
		int ans = (sum(l,l + jarak - 1) / 10) + (sum(l + jarak,r) / 10);
		ans += ((sum(l,l + jarak - 1) % 10) + (sum(l + jarak,r) % 10)) / 10;
		cout << ans << endl;
	}
}