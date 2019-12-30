#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int frek[200010];
int n;

int find_min()
{
	int ret = 0;
	int i = 1; 
	while (i <= n)
	{
		if (!frek[i]) ++i;
		else
		{
			++ret;
			i += 3;
		}
	}
	return ret;
}

int find_max()
{
	int ret = 0;
	int i = 1;
	int dist = 0;
	bool kosong = 1;
	while (i <= n)
	{
		// cout << i << endl;
		if (!frek[i])
		{
			++dist;
			++i;
			continue;
		}
		int j = i;
		int sum = 0;
		while (j <= n && frek[j])
		{
			// cout << j << " " << frek[j] << endl;
			sum += frek[j];
			++j;
		}
		// cout << i << " " << j << endl;
		ret += j - i;
		// cout << sum << endl;
		if (sum > j - i && (kosong || dist > 1))
		{
			--sum;
			++ret;
		}
		kosong = 1;
		if (sum > j - i)
		{
			kosong = 0;
			++ret;
		}
		i = j;
		dist = 0;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		frek[ta]++;
	}
	cout << find_min() << " " << find_max() << endl;
}