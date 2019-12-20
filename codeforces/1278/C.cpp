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

int leftBal[100010];
int rightBal[100010];
int leftTab[100010];
int rightTab[100010];
map<int,int> leftPos;
map<int,int> rightPos;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		leftPos.clear();
		rightPos.clear();
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
			cin >> leftTab[i];
		for (int i = n ; i >= 1 ; i--)
			 cin >> rightTab[i];
		for (int i = 1 ; i <= n ; i++) {
			leftBal[i] = leftBal[i - 1];
			rightBal[i] = rightBal[i - 1];
			if (leftTab[i] == 1)
				leftBal[i]++;
			else
				leftBal[i]--;
			if (rightTab[i] == 1)
				++rightBal[i];
			else
				--rightBal[i];
			leftPos[leftBal[i]] = i;
			rightPos[rightBal[i]] = i;
		}
		int ans = 2 * n;
		for (int i = n ; i >= 0 ; i--) {
			int curBal = rightBal[i];
			if (leftPos.count(-curBal)) {
				ans = min(ans,(n - i) + (n - leftPos[-curBal]));
			}
			curBal = leftBal[i];
			if (rightPos.count(-curBal)) {
				ans = min(ans,(n - i) + (n - rightPos[-curBal]));
			}
		}
		cout << ans << endl;
	}
}