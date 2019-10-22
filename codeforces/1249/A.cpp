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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
			cin >> tab[i];
		sort(tab + 1,tab + n + 1);
		bool ada = 0;
		for (int i = 2 ; i <= n ; i++) {
			ada |= (tab[i] - tab[i - 1] == 1);
		}
		int ans = 1 + ada;
		cout << ans << endl;
	}
}