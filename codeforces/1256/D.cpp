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

string s;
string ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n,k;
		cin >> n >> k;
		cin >> s;
		ans = s;
		for (int i = 0 ; i < n ; i++)
			ans[i] = '-';
		queue< pair<int,int> > needs;
		int nxt = 0;
		for (int i = 0 ; i < n ; i++) if (s[i] == '0') {
			needs.push({i - nxt,i});
			++nxt;
		}
		while (!needs.empty() && k > 0) {
			int step = needs.front().first;
			int pos = needs.front().second;
			needs.pop();
			if (k >= step) {
				k -= step;
				ans[pos - step] = '0';
			}
			else {
				ans[pos - k] = '0';
				k = 0;
			}
		}
		while (!needs.empty()) {
			ans[needs.front().second] = '0';
			needs.pop();
		}
		for (int i = 0 ; i < n ; i++) if (ans[i] == '-')
			ans[i] = '1';
		cout << ans << endl;
	}
}