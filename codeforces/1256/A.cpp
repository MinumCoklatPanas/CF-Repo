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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a,b,n,s;
		cin >> a >> b >> n >> s;
		if (b >= s) {
			cout << "YES\n";
			continue;
		}
		int bagi = s / n;
		int sisa = s % n;
		if (a >= bagi) {
			if (b >= sisa)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else {
			int kurang = (bagi * n) - (a * n);
			if (b >= kurang) {
				b -= kurang;
				if (b >= sisa)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
			else
				cout << "NO\n";
		}
	}
}