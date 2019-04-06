#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,h;
	cin >> n >> h;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int ans = -1;
	for (int i = 1 ; i <= n ; i++)
	{
		priority_queue<int> pq;
		for (int j = 1 ; j <= i ; j++)
			pq.push(tab[j]);
		bool bisa = 1;
		int mx = 0;
		// cout << i << " i\n";
		while (!pq.empty())
		{
			int kiri = pq.top();
			pq.pop();
			int kanan = (pq.empty() ? 0 : pq.top());
			if (!pq.empty())
			 pq.pop();
			// cout << kiri << " kiri " << mx << endl;
			if (mx + kiri > h)
			{
				bisa = 0;
				break;
			}
			mx += kiri;
		}
		if (bisa)
			ans = i;
		else
			break;
	}
	// assert(ans != -1);
	cout << ans << endl;
}