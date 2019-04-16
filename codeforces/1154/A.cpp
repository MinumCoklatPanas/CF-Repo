#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 2e5;
const ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll tab[4];
	cin >> tab[0] >> tab[1] >> tab[2] >> tab[3];
	sort(tab,tab + 4);
	ll abc = tab[3];
	ll a = tab[0] - abc;
	ll b = tab[1] - abc;
	ll c = tab[2] - abc;
	cout << -a << " " << -b << " " << -c << endl;
}