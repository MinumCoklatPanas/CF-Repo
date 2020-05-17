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
	int t;
	cin >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		if (n % 2 == 1 && k % 2 == 0)
			cout << "NO\n";
		else
		{
			vector< int > ans;
			int start;
			if (n % 2 == 0 && k % 2 == 1)
				start = 2;
			else
				start = 1;
			while (n > 0 && ans.size() < k - 1)
			{
				ans.push_back(start);
				n -= start;
			}
			if (n > 0)
				ans.push_back(n);
			if (ans.size() != k)
				cout << "NO\n";
			else
			{
				cout << "YES\n";
				for (auto it : ans)
					cout << it << " ";
				cout << endl;
			}
		}
	}
	return 0;
}