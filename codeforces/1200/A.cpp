#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool ada[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0 ; i < n ; i++)
	{
		if (s[i] == 'L')
		{
			for (int j = 0 ; j < 10 ; j++)
				if (!ada[j])
				{
					ada[j] = 1;
					break;
				}
		}
		else
		if (s[i] == 'R')
		{
			for (int j = 9 ; j >= 0 ; j--)
			{
				if (!ada[j])
				{
					ada[j] = 1;
					break;
				}
			}
		}
		else
			ada[s[i] - '0'] = 0;
	}
	for (int i = 0 ; i < 10 ; i++)
		cout << ada[i];
	cout << endl;
}