#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
#define pb push_back
#define debug(x) cout << x << endl
#define NeedForSpeed ios_base::sync_with_stdio(0), cin.tie(0)
#define PI acos(-1)
#define all(c) c.begin(), c.end()
#define SET(x, y) memset((x), y, sizeof(x))
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const ll INF64 = 1e18;
 
const int N = 1e5 + 5;

int cnt(int x) {
	int ret = 0;
	while (x) {
		++ret;
		x /= 2;
	}
	return ret;
}

int main() {
	NeedForSpeed;
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		int n;
		cin >> n;
		priority_queue< int > pq;
		for (int i = 1 ; i <= n ; i++) {
			int ta;
			cin >> ta;
			if (ta % 2 == 0) {
				pq.push(ta);
			}
		}
		int bef = -1;
		while (!pq.empty()) {
			int ta = pq.top();
			// cout << ta << endl;
			pq.pop();
			if (ta != bef)
				++ans;
			bef = ta;
			ta /= 2;
			if (ta % 2 == 0)
				pq.push(ta);
		}
		cout << ans << endl;
	}
	return 0;
}