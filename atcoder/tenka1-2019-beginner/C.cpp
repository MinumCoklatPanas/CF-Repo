#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int tab[200010];
int pref[2][200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		pref[0][i] = pref[0][i - 1];
		pref[1][i] = pref[1][i - 1];
		char ta;
		cin >> ta;
		if (ta == '.')
			++pref[0][i];
		else
			++pref[1][i];
	}
	int ans = INF;
	//batas putih
	for (int i = 0 ; i <= n ; i++)
	{
		int PutihKanan = pref[0][n] - pref[0][i];
		int HitamKiri = pref[1][i];
		int cnt = PutihKanan + HitamKiri;
		ans = min(ans,cnt);
	}
	cout << ans << endl;
}