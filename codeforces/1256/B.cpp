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

int tab[110];
int n;

int findSmallest(int curPos) {
	int mn = INF;
	int pos = -1;
	for (int i = curPos ; i <= n ; i++) {
		if (tab[i] < mn) {
			mn = tab[i];
			pos = i;
		}
	}
	return pos;
}

void bringFront(int from,int to) {
	for (int i = from ; i > to ; i--)
		swap(tab[i],tab[i - 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
			cin >> tab[i];
		int curPos = 1;
		while (curPos <= n) {
			int nxt = findSmallest(curPos);
			if (nxt == curPos) {
				++curPos;
				continue;
			}
			bringFront(nxt,curPos);
			curPos = nxt;
		}
		for (int i = 1 ; i <= n ; i++) {
			if (i == n)
				cout << tab[i] << endl;
			else
				cout << tab[i] << " ";
		}
	}
}