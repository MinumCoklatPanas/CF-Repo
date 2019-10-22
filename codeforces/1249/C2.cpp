#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool cek(ll x) {
	while (x) {
		if (x % 3 == 2) return 0;
		x /= 3;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (cek(n))
			cout << n << endl;
		else {
			deque< int > bit;
			while (n) {
				bit.push_back(n % 3);
				n /= 3;
			}
			reverse(bit.begin(),bit.end());
			int pos1 = -1;
			for (int i = 0 ; i < bit.size() ; i++) {
				if (bit[i] == 2) {
					pos1 = i;
					break;
				}
			}
			assert(pos1 != -1);
			// cout << pos1 << endl;
			int pos2 = -1;
			for (int i = 0 ; i < pos1 ; i++) {
				if (bit[i] == 0) {
					pos2 = i;
					// break;
				}
			}
			// cout << pos2 << endl;
			if (pos2 == -1) {
				for (int i = 0 ; i < bit.size() ; i++)
					bit[i] = 0;
				bit.push_front(1);
			}
			else {
				bit[pos2] = 1;
				for (int i = pos2 + 1 ; i < bit.size() ; i++)
					bit[i] = 0;
			}
			reverse(bit.begin(),bit.end());
			ll cur = 1ll;
			ll ans = 0ll;
			for (int i = 0 ; i < bit.size() ; i++) {
				ans += cur * bit[i];
				cur *= 3;
			}
			cout << ans << endl;
		}
	}
}