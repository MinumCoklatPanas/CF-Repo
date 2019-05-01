#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int bulat =1 ;
int kotak = 3;
int segitiga = 2;
int tab[110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int last;
	cin >> last;
	tab[1] = last;
	int ans = 0;
	for (int i = 2 ; i <= n ; i++)
	{
		int ta;
		cin >> ta;
		tab[i] = ta; 
		if ((last == kotak && ta == segitiga) || 
			(last == segitiga && ta == kotak))
		{
			cout << "Infinite\n";
			return 0;
		}
		else
		if (i >= 3 && 
			ta == segitiga &&
			tab[i - 1] == bulat &&
			tab[i - 2] == kotak)
			ans += 2;
		else
		if (last == segitiga || ta == segitiga)
			ans += 3;
		else
		if (last == kotak || ta == kotak)
			ans += 4;
		last = ta;
	}
	cout << "Finite\n";
	cout << ans << endl;
}