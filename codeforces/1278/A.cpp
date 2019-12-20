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

int frek[30];
int pref[30][110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(frek,0,sizeof(frek));
		memset(pref,0,sizeof(pref));
		string ta;
		string hash;
		cin >> ta >> hash;
		for (int i = 0 ; i < ta.length() ; i++) {
			frek[ta[i] - 'a']++;
		}
		for (int i = 0 ; i < hash.length() ; i++) {
			if (i > 0) {
				for (int j = 0 ; j < 26 ; j++)
					pref[j][i] = pref[j][i - 1];
			}
			pref[hash[i] - 'a'][i]++;
		}
		int len = ta.length();
		bool can = 0;
		for (int i = len - 1 ; i < hash.length() ; i++) {
			int left = i - (len - 1);
			// cout << i << " " << left << endl;
			can = 1;
			for (int j = 0 ; j < 26 ; j++) {
				int sum = pref[j][i] - (left == 0 ? 0 : pref[j][left - 1]);
				if (sum != frek[j]) {
					// cout << i << " " << j << " " << sum << " " << frek[j] << endl;
					can = 0;
					break;
				}
			}
			if (can) break;
		}
		if (can)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}