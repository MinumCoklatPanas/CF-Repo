#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

char s[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
		cin >> s[i];
	int k;
	cin >> k;
	for (int i = 1 ; i <= n ; i++) if (s[i] != s[k])
		s[i] = '*';
	for (int i = 1 ; i <= n ; i++)
		cout << s[i];
	cout << endl;
}