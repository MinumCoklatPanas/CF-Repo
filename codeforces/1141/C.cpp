#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll INFF = 1e18;
const ll MAXN = 2e5;
const ll MOD = 1e9 + 7;

ll tab[200010];
map<ll,bool> sudah;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 1 ; i < n ; i++)
		cin >> tab[i];
	ll BatasBawah = 1;
	ll BatasAtas = n;
	ll sum = 0;
	for (ll i = 1 ; i < n ; i++)
	{
		sum += tab[i];
		if (sudah[sum] || sum == 0)
		{
			cout << -1 << endl;
			return 0;
		}
		sudah[sum] = 1;
		//update batas bawah
		if (sum < 0)
		{
			ll tmp = abs(sum) + 1;
			if (tmp > BatasAtas)
			{
				cout << -1 << endl;
				return 0;
			}
			BatasBawah = max(BatasBawah,tmp);
		}
		//update batas atas
		else
		{
			ll tmp = n - sum;
			if (tmp < BatasBawah)
			{
				cout << -1 << endl;
				return 0;
			}
			BatasAtas = min(BatasAtas,tmp);
		}
	}
	// cout << BatasBawah << " " << BatasAtas << endl;
	ll now = BatasBawah;
	sum = 0;
	cout << now << " ";
	for (ll i = 1 ; i < n ; i++)
	{
		sum += tab[i];
		cout << now + sum << " ";
	}
	cout << endl;
}