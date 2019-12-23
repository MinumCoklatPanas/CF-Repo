#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

pair<int,int> tab[1010];
bool sudah[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		int tot = 0;
		for (int i = 1 ; i <= n ; i++) {
			cin >> tab[i].first;
			tab[i].second = i;
			tot += tab[i].first;
		}
		sort(tab + 1,tab + n + 1);
		if (m < n || n < 3) {
			cout << -1 << endl;
			continue;
		}
		cout << 2 * tot << endl;
		for (int i = 1 ; i <= n ; i++) {
			if (i == n)
				cout << i << " " << 1 << endl;
			else
				cout << i << " " << i + 1 << endl;
		}
	}
}