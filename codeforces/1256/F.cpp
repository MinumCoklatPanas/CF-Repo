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

int cnt[2][30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cnt,0,sizeof(cnt));
		int n;
		cin >> n;
		string s1,s2;
		cin >> s1 >> s2;
		for (int i = 0 ; i < n ; i++) {
			cnt[0][s1[i] - 'a']++;
			cnt[1][s2[i] - 'a']++;
		}
		bool can = 1;
		for (int i = 0 ; i < 26 ; i++) {
			if (cnt[0][i] != cnt[1][i]) {
				can = 0;
				break;
			}
		}
		if (!can) {
			cout << "NO\n";
			continue;
		}
		int inv1,inv2;
		for (int i = 0 ; i < 26 ; i++) {
			if (cnt[0][i] > 1) {
				cout << "YES\n";
				goto hell;
			}
		}
		inv1 = 0;
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < i ; j++)
				inv1 += (s1[i] < s1[j]);
		inv2 = 0;
		for (int i = 0 ; i < n ; i++)
			for (int j = 0 ; j < i ; j++)
				inv2 += (s2[i] < s2[j]);
		if ((inv1 % 2) == (inv2 % 2))
			cout << "YES\n";
		else
			cout << "NO\n";
		hell:;
	}
}