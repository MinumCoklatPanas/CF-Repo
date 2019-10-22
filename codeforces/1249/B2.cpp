#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int cnt[200010];
int tab[200010];
int par[200010];

int finds(int x) {
	return (par[x] == x ? x : par[x] = finds(par[x]));
}

void joins(int x,int y) {
	int px = finds(x);
	int py = finds(y);
	if (px == py) return;
	par[px] = py;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> tab[i];
			par[i] = i;
			cnt[i] = 0;
		}
		for (int i = 1 ; i <= n ; i++) {
			joins(i,tab[i]);
		}
		for (int i = 1 ; i <= n ; i++)
			cnt[finds(i)]++;
		for (int i = 1 ; i <= n ; i++) {
			if (i == n)
				cout << cnt[finds(i)] << endl;
			else
				cout << cnt[finds(i)] << " ";
		}
	}
}