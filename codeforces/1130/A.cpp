#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int pos = 0;
	int neg = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		pos += (tab[i] > 0);
		neg += (tab[i] < 0);
	}
	if ((pos >= (n / 2) + (n % 2)))
		cout << 1 << endl;
	else
	if (neg >= (n / 2) + (n % 2))
		cout << -1 << endl;
	else
		cout << 0 << endl;
}