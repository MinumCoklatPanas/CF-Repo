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

int cei(int x,int y)
{
	return ((x / y) + (x % y != 0));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,a,b,k;
	cin >> n >> a >> b >> k;
	int ans = 0;
	priority_queue< int, vector< int >, greater< int > > pq;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		int rem = ta % (a + b);
		if (rem <= a && rem != 0)
		{
			// cout << i << " ";
			++ans;
		}
		else
		if (k)
		{
			if (rem == 0)
			{
				// cout << "yo\n";
				// cout << rem << endl;
				int need = cei(a + b,a) - 1;
				// cout << need << endl;
				pq.push(need);
			}	
			else
			if (rem <= a + b)
			{
				int need = cei(rem,a) - 1;
				pq.push(need);
			}
			else
			{
				// --k;
				pq.push(1);
				// ++ans;
			}
		}
	}
	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		// cout << cur << endl;
		if (cur > k) break;
		++ans;
		k -= cur;
	}
	// cout << endl;
	cout << ans << endl;
	return 0;
}