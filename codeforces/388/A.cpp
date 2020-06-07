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

int stek[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue< int,vector<int>,greater<int> > pq;
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		pq.push(ta);
	}
	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		for (int i = 1 ; i <= 100 ; i++)
		{
			if (stek[i] <= cur)
			{
				++stek[i];
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1 ; i <= 100 ; i++)
		ans += (stek[i] != 0);
	cout << ans << endl;
	return 0;
}