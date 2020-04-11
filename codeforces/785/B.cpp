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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int min_end_chess = INF;
	int max_end_chess = -INF;
	int min_start_chess = INF;
	int max_start_chess = -INF;
	for (int i = 1 ; i <= n ; i++)
	{
		int l,r;
		cin >> l >> r;
		min_end_chess = min(min_end_chess,r);
		max_end_chess = max(max_end_chess,r);
		min_start_chess = min(min_start_chess,l);
		max_start_chess = max(max_start_chess,l);
	}
	int m;
	cin >> m;
	int min_end_prog = INF;
	int max_end_prog = -INF;
	int min_start_prog = INF;
	int max_start_prog = -INF;
	for (int i = 1 ; i <= m ; i++)
	{
		int l,r;
		cin >> l >> r;
		min_end_prog = min(min_end_prog,r);
		max_end_prog = max(max_end_prog,r);
		min_start_prog = min(min_start_prog,l);
		max_start_prog = max(max_start_prog,l);
	}
	int ans = max(max_start_prog - min_end_chess,max_start_chess - min_end_prog);
	ans = max(ans,0);
	cout << ans << endl;
	return 0;
}