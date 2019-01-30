#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 100000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	// cout << "yo" << endl;
	// cout << q << endl;
	while (q--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		if (s.length() > 2)
		{
			cout << "YES\n";
			cout << 2 << endl;
			cout << s[0] << " " ;
			for (int i = 1 ; i < n ; i++)
				cout << s[i];
			cout << endl;
		}
		else
		{
			if (s[1] <= s[0])
				cout << "NO" << endl;
			else
			{
				cout << "YES" << endl;
				cout << 2 << endl;
				cout << s[0] << " " << s[1] << endl;
			}
		}
	}
}