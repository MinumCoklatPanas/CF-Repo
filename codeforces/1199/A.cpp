#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,x,y;
	cin >> n >> x >> y;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	for (int i = 1 ; i <= n ; i++)
	{
		bool bisa = 1;
		for (int j = max(1,i - x) ; j < i ; j++)
			if (tab[j] <= tab[i])
			{
				bisa = 0;
				break;
			}
		for (int j = i + 1 ; j <= min(n,i + y) ; j++)
			if (tab[j] <= tab[i])
			{
				bisa = 0;
				break;
			}
		if (bisa)
		{
			cout << i << endl;
			return 0;
		}
	}
}