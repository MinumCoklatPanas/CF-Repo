#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int l = 1;
	int r = n;
	vector<char> ans;
	int last = 0;
	while (l <= r)
	{
		if (tab[l] < last && tab[r] < last) break;
		if (tab[l] > last && tab[r] > last)
		{
			if (tab[l] < tab[r])
			{
				last = tab[l];
				++l;
				ans.push_back('L');
			}
			else
			{
				last = tab[r];
				--r;
				ans.push_back('R');
			}
		}
		else
		if (tab[l] > last)
		{

			last = tab[l];
			++l;
			ans.push_back('L');
		}
		else
		{
			last = tab[r];
			--r;
			ans.push_back('R');
		}
	}
	cout << ans.size() << endl;
	for (int i = 0 ; i < ans.size() ; i++)
		cout << ans[i];
	cout << endl;
}