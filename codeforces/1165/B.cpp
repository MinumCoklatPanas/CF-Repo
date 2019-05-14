#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

multiset<int> ms;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;

		ms.insert(ta);
	}
	for (int i = 1 ; i <= n ; i++)
	{
		// cout << i << endl;
		multiset<int>::iterator it = ms.lower_bound(i);
		if (it == ms.end())
		{
			cout << i - 1 << endl;
			return 0;
		}
		ms.erase(it);
	}
	cout << n << endl;
}