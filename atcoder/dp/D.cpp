#include <bits/stdc++.h>
using namespace std;

long long DP[110][100010];
long long w[110];
long long v[110];
long long n,W;

long long rec(long long index,long long sisa)
{
	if (index > n) return 0;
	if (DP[index][sisa] != -1) return DP[index][sisa];
	long long ret = rec(index + 1,sisa);
	if (w[index] <= sisa)
	{
		// cout << index << " " << sisa << endl;
		ret = max(ret,v[index] + rec(index + 1,sisa - w[index]));
	}
	return DP[index][sisa] = ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(DP,-1,sizeof(DP));
	cin >> n >> W;
	for (long long i = 1 ; i <= n ; i++)
	{
		cin >> w[i] >> v[i];
	}
	long long ans = rec(1,W);
	cout << ans << endl;
}