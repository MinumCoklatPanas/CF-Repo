#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		ll candy[5];
		cin >> candy[0] >> candy[1] >> candy[2];
		cout << (candy[0] + candy[1] + candy[2]) / 2 << endl;
		continue;
		ll ans = 0ll;
		do 
		{
			ll mn = min(candy[0],candy[1]);
			ll mx = max(candy[0],candy[1]);
			ll sisa = candy[2];
			ll nambah = min(candy[2],mx - mn);
			mn += nambah;
			sisa -= nambah;
			mn += sisa / 2;
			ans = max(ans,mn);

		} while (next_permutation(candy,candy + 3));
		cout << ans << endl;
	}	
}