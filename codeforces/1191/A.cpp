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
	int x;
	cin >> x;
	if (x % 4 == 1)
	{
		cout << "0 A\n";
	}
	else
	if (x % 4 == 3)
	{
		cout << "2 A\n";
	}
	else
	if (x % 4 == 2)
	{
		cout << "1 B\n";
	}
	else
	{
		cout << "1 A\n";
	}
}