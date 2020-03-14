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

int tab[110];

bool check(int n)
{
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j < i ; j++)
			if (j - tab[j] == i - tab[i]) return false;
	return true;
}

void print(int n)
{
	for (int i = 1 ; i <= n ; i++)
		cout << tab[i] << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(108230183);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1 ; i <= n ; i++)
			cin >> tab[i];
		sort(tab + 1,tab + n + 1);
		if (check(n))
			print(n);
		else
		{
			reverse(tab + 1,tab + n + 1);
			print(n);
		}
	}
	return 0;
}