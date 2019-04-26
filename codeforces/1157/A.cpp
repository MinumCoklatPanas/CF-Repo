#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

map<int,bool> sudah;
int awal = 1;

int rec(int x)
{
	if (sudah[x]) return 0;
	sudah[x] = 1;
	++x;
	while (x % 10 == 0)
		x /= 10;
	return 1 + rec(x);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x;
	cin >> x;
	int ans = rec(x);
	cout << ans << endl;
}