#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool bisa[30];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		s += ' ';
		memset(bisa,0,sizeof(bisa));
		int i = 0;
		while (i + 1 < s.length()) {
			int cnt = 0;
			char cur = s[i];
			while (cur == s[i]) {
				++cnt;
				++i;
			}
			bisa[cur - 'a'] |= (cnt % 2);
		}
		for (int i = 0 ; i < 26 ; i++) if (bisa[i])
			cout << (char)('a' + i);
		cout << endl;
	}
}