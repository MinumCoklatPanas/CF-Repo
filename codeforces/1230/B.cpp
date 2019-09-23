#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[200010];
bool ubah[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	if (k == 0)
	{
		cout << s << endl;
		return 0;
	}
	for (int i = 0 ; i < n ; i++)
		tab[i + 1] = s[i] - '0';
	if (n == 1)
	{
		cout << "0\n";
	}
	else
	{
		for (int i = 1 ; i <= n ; i++) if (k)
		{
			if (i == 1)
			{
				if (tab[i] != 1)
				{
					tab[i] = 1;
					ubah[1] = 1;
					--k;
				}
			}
			else
			{
				if (tab[i] != 0)
				{
					tab[i] = 0;
					ubah[i] = 1;
					--k;
				}
			}
		}
		for (int i = 1 ; i <= n ; i++)
			cout << tab[i];
		cout << endl;
		return 0;
		if (k)
		{
			for (int i = 1 ; i <= n ; i++) if (k && !ubah[i])
			{
				if (tab[i] == 0)
				{
					++tab[i];
					--k;
					ubah[i] = 1;
				}
			}
		}
		if (k)
		{
			assert(k == 1);
			assert(tab[1] == 1);
			tab[1]++;
		}
	}
}