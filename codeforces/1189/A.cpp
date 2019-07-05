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
	int n;
	cin >> n;
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0 ; i < n ; i++)
		cnt += (s[i] == '1');
	if (cnt + cnt == n)
	{
		cout << 2 << endl;
		for (int i = 0 ; i < n - 1 ; i++)
			cout << s[i];
		cout << " ";
		cout << s[n - 1] << endl;
	}
	else
	{
		cout << 1 << endl;
		cout << s << endl;
	}
}