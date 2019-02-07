#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 1e5;
const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int b,k;
	cin >> b >> k;
	int par = 0;
	for (int i = 1 ; i <= k ; i++)
	{
		int a;
		cin >> a;
		if (i == k)
			par += (a % 2);
		else
			par += (a % 2) * (b % 2);
		par %= 2;
	}
	if (par == 0)
		cout << "even" << endl;
	else
		cout << "odd" << endl;
}