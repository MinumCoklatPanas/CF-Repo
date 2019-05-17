#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int frek[30];

int cnt(int x)
{
	return (x * (x - 1)) / 2;
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
		string s;
		cin >> s;
		frek[s[0] - 'a' + 1]++;
	}
	int ans = 0;
	for (int i = 1 ; i <= 26 ; i++)
	{
		int kiri = frek[i] / 2;
		int kanan = kiri + (frek[i] % 2);
		ans += cnt(kiri) + cnt(kanan);
	}
	cout << ans << endl;
}