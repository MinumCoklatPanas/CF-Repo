#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int cnt[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		cnt[ta]++;
	}
	int ganjil = 0;
	for (int i = 1 ; i <= k ; i++)
		ganjil += (cnt[i] % 2);
	int ans = n - (ganjil / 2);
	cout << ans << endl;
}