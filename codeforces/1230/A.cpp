#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n = 4;
	int sum = 0;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> tab[i];
		sum += tab[i];
	}
	for (int i = 0 ; i < (1 << n) ; i++)
	{
		int ambil = 0;
		for (int j = 0 ; j < n ; j++) if (i & (1 << j))
			ambil += tab[j];
		if (ambil * 2 == sum)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}