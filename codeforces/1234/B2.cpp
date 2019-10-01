#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

map<int,bool> ada;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	deque< int > dq;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		if (!ada[ta])
		{
			ada[ta] = 1;
			if (dq.size() == k)
			{
				ada[dq.back()] = 0;
				dq.pop_back();
			}
			dq.push_front(ta);
 		}
	}
	cout << dq.size() << endl;
	for (int i = 0 ; i < dq.size() ; i++)
	{
		cout << dq[i] << " ";
	}
	cout << endl;
}