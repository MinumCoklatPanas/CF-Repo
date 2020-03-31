#include <bits/stdc++.h>
using namespace std;
 
//Made with <3 by MinumCoklatPanas
typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		int u,v,x1,y1,x2,y2;
		cin >> u >> v >> x1 >> y1 >> x2 >> y2;
		int atas = max(0,d - c);
		int bawah = max(0,c - d);
		int kiri = max(0,a - b);
		int kanan = max(0,b - a);
		bool cek = 1;
		cek &= (y2 - v) >= atas;
		cek &= (v  - y1) >= bawah;
		cek &= (x2 - u) >= kanan;
		cek &= (u - x1) >= kiri;
		if (y1 == v && v == y2 && (c > 0 || d > 0))
			cek = false;
		if (x1 == u && u == x2 && (a > 0 || b > 0))
			cek = false;
		if (cek)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
