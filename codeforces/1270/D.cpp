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

map<int,int> frek;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	int mx = -INF;
	for (int i = 1 ; i <= k + 1 ; i++)
	{
		cout << "? ";
		for (int j = 1 ; j <= k + 1 ; j++) if (j != i)
		{
			cout << j << " ";
		}
		cout << endl;
		cout << flush;
		int val,pos;
		cin >> pos >> val;
		frek[val]++;
		mx = max(mx,val);
	}
	cout << "! " << frek[mx] << endl;
	cout << flush;
}