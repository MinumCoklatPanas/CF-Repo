#include <bits/stdc++.h>
using namespace std;

long long BIT[200010];
long long tab[200010];
long long val[200010];

void upd(long long x,long long val)
{
	for ( ; x <= 200000 ; x += (x & -x))
		BIT[x] = max(BIT[x],val);
}

long long query(long long x)
{
	long long res = 0;
	for ( ; x ; x -= (x & -x))
		res = max(res,BIT[x]);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	for (long long i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
	}
	for (long long i = 1 ; i <= n ; i++)
		cin >> val[i];
	long long ans = 0;
	for (long long i = 1 ; i <= n ; i++)
	{
		long long tmp = query(tab[i] - 1);
		tmp += val[i];
		// cout << tmp << endl;
		ans = max(ans,tmp);
		upd(tab[i],tmp);
	}
	cout << ans << endl;
}