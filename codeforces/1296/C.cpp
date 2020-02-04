#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

map< pair< int,int >,vector< int > > leftMost;
char tab[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		leftMost.clear();
		int n;
		cin >> n;
		pair<int,int> delta = {0,0};
		leftMost[delta].push_back(0);
		for (int i = 1 ; i <= n ; i++)
		{
			cin >> tab[i];
			if (tab[i] == 'L')
				--delta.first;
			else
			if (tab[i] == 'R')
				++delta.first;
			else
			if (tab[i] == 'U')
				++delta.second;
			else
				--delta.second;
			leftMost[delta].push_back(i);
		}
		pair<int,int> curDelta = {0,0};
		int len = INF;
		int l = -1,r = -1;
		for (int i = 0 ; i < n ; i++)
		{
			if (tab[i] == 'L')
				--curDelta.first;
			else
			if (tab[i] == 'R')
				++curDelta.first;
			else
			if (tab[i] == 'U')
				++curDelta.second;
			else
			if (tab[i] == 'D')
				--curDelta.second;
			if (leftMost[curDelta].back() == i)
				continue;
			int pos = upper_bound(leftMost[curDelta].begin(),leftMost[curDelta].end(),i) - leftMost[curDelta].begin();
			int R = leftMost[curDelta][pos];
			int L = i + 1;
			if (R - L + 1 < len)
			{
				len = R - L + 1;
				l = L;
				r = R;
			}
		}
		if (len == INF)
			cout << -1 << endl;
		else
			cout << l << " " << r << endl;
	}
	return 0;
}