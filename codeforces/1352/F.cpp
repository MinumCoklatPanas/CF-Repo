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
		int n0,n1,n2;
		cin >> n0 >> n1 >> n2;
		if (n0)
			cout << "0";
		for (int i = 1 ; i <= n0 ; i++)
			cout << "0";
		if (!n0 && n1)
			cout <<  "0";
		for (int i = 1 ; i <= n1 - (n1 % 2 == 0) ; i++)
		{
			if (i % 2 == 1)
				cout << "1";
			else
				cout << "0";
		}
		if (!n1 && n2)
			cout << "1";
		for (int i = 1 ; i <= n2 ; i++)
			cout << "1";
		if (n1 % 2 == 0 && n1 != 0)
			cout << "0";
		cout << endl;
	}
	return 0;
}