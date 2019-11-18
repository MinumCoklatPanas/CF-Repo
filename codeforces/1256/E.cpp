#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 510;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

pair< ll,ll > tab[200010];
ll dp[200010];
ll team[200010];
bool change[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i <= n ; i++) {
		cin >> tab[i].first;
		tab[i].second = i;
	}
	sort(tab + 1,tab + n + 1);
	dp[1] = dp[2] = INFF;
	ll cnt = 1;
	for (ll i = 3 ; i <= n ; i++) {
		if (dp[i - 1] + tab[i].first - tab[i - 1].first < dp[i - 3] + tab[i].first - tab[i - 2].first) {
			team[tab[i].second] = cnt + 1;
			dp[i] = dp[i - 1] + tab[i].first - tab[i - 1].first;
		}
		else {
			change[i] = 1;
			dp[i] = dp[i - 3] + tab[i].first - tab[i - 2].first;
			team[tab[i].second] = cnt;
		}
	}
	int i = n;
	while (i > 0) {
		team[tab[i].second] = cnt;
		if (change[i]) {
			team[tab[i - 1].second] = team[tab[i - 2].second] = cnt;
			++cnt;
			i -= 3;
		}
		else
			--i;
	}
	cout << dp[n] << " " << cnt - 1 << endl;
	for (int i = 1 ; i <= n ; i++) {
		if (i == n)
			cout << team[i] << endl;
		else
			cout << team[i] << " ";
	}
}