#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[210];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
			cin >> tab[i];
		bool bisa1 = 1,bisa2 = 1;
		int now = tab[1];
		for (int i = 2 ; i <= n ; i++)
		{
			int nxt = (now + 1) % n;
			if (nxt == 0)
				nxt = n;
			if (nxt != tab[i])
			{
				bisa1 = 0;
				break;
			}
			now = tab[i];
		}
		reverse(tab + 1,tab + n + 1);
		now = tab[1];
		for (int i = 2 ; i <= n ; i++)
		{
			int nxt = (now + 1) % n;
			if (nxt == 0)
				nxt = n;
			if (nxt != tab[i])
			{
				bisa2 = 0;
				break;
			}
			now = tab[i];
		}
		if (!bisa1 && !bisa2)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}