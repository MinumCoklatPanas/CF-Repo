#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e5;
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
		int n;
		cin >> n;
		int loBoX = -INF;
		int upBoX = INF;
		int loBoY = -INF;
		int upBoY = INF;
		bool goblok = 1;
		for (int i = 1 ; i <= n ; i++)
		{
			int x,y;
			cin >> x >> y;
			int bisaKiri,bisaAtas,bisaKanan,bisaBawah;
			cin >> bisaKiri >> bisaAtas >> bisaKanan >> bisaBawah;
			int cur_loBoX = -INF;
			int cur_upBoX = INF;
			int cur_loBoY = -INF;
			int cur_upBoY = INF;
			if (!bisaKiri)
				cur_loBoX = x;
			if (!bisaKanan)
				cur_upBoX = x;
			if (!bisaAtas)
				cur_upBoY = y;
			if (!bisaBawah)
				cur_loBoY = y;
			// cout << cur_loBoX << " " << cur_upBoX << " " << cur_loBoY << " " << cur_upBoY << endl;
			if ((cur_loBoX > upBoX) ||
				(cur_upBoX < loBoX) ||
				(cur_loBoY > upBoY) ||
				(cur_upBoY < loBoY))
			{
				goblok = 0;
				// break;
			}
			loBoX = max(loBoX,cur_loBoX);
			loBoY = max(loBoY,cur_loBoY);
			upBoX = min(upBoX,cur_upBoX);
			upBoY = min(upBoY,cur_upBoY);
		}
		if (goblok)
			cout << "1 " << loBoX << " " << loBoY << endl;
		else
			cout << "0\n";
	}
}