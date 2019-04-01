#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int tab[20];

int cek(int l,int r)
{
	bool bisa = 1;
	for (int i = l ; i < r ; i++)
	{
		if (tab[i] > tab[i + 1])
		{
			bisa = 0;
			break;
		}
	}
	if (bisa) return r - l + 1;
	int mid = (r + l) / 2;
	return max(cek(l,mid),cek(mid + 1,r));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> tab[i];
	int ans = cek(1,n);
	cout << ans << endl;
}