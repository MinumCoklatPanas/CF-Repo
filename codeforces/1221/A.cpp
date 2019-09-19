#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		priority_queue< int,vector<int>,greater<int> > pq;
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
		{
			int ta;
			cin >> ta;
			if (ta <= 2048)
				pq.push(ta);
		}
		bool can = 0;
		while (pq.size() > 1)
		{
			int cur1 = pq.top();
			if (cur1 == 2048)
			{
				can = 1;
				break;
			}
			pq.pop();
			if (pq.top() != cur1) continue;
			int cur2 = pq.top();
			pq.pop();
			pq.push(cur1 * 2);
		}
		while (!pq.empty())
		{
			if (pq.top() == 2048)
			{
				can = 1;
				break;
			}
			pq.pop();
		}
		if (can)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}