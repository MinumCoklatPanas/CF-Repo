#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[300010];
int ans[300010];

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
		int n = s.length();
		for (int i = 0 ; i < n ; i++)
			tab[i] = s[i] - '0';
		deque< int > dq;
		dq.push_back(tab[0]);
		int curPos = 0;
		for (int i = 1 ; i < n ; i++) {
			if (dq.empty())
				dq.push_back(tab[i]);
			else {
				if ((tab[i] % 2) == (dq.back() % 2)) {
					dq.push_back(tab[i]);
				}
				else {
					while (!dq.empty() && dq.front() < tab[i]) {
						ans[curPos++] = dq.front();
						dq.pop_front();
					}
					if (dq.
						empty())
						dq.push_back(tab[i]);
 					else {
 						ans[curPos++] = tab[i];
 					}
				}
			}
		}
		// cout << dq.size() << endl;
		while (!dq.empty()) {
			ans[curPos++] = dq.front();
			dq.pop_front();
		}
		assert(curPos == n);
		for (int i = 0 ; i < n ; i++)
			cout << ans[i];
		cout << endl;
	}
}