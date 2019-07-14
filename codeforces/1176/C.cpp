#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int akhir[10];
int convert[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	convert[4] = 1;
	convert[8] = 2;
	convert[15] = 3;
	convert[16] = 4;
	convert[23] = 5;
	convert[42] = 6;
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		ta = convert[ta];
		if (ta == 1)
			++akhir[ta];
		else
		if (akhir[ta - 1] > 0)
		{
			--akhir[ta - 1];
			++akhir[ta];
		}
	}
	// cout << akhir[6] << endl;
	int bikin = 6 * akhir[6];
	// cout << bikin << endl;
	int ans = n - bikin;
	cout << ans << endl;
}