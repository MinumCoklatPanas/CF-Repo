#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

int ubah[10];
bool bisa[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin >> n;
	cin >> s;
	for (int i = 1 ; i < 10 ; i++)
	{
		cin >> ubah[i];
		bisa[i] = (ubah[i] > i);
	}
	for (int i = 0 ; i < n ; i++)
	{
		if (ubah[s[i] - '0'] > s[i] - '0')
		{
			// char simpan = s[i];
			for (int j = i ; j < n ; j++)
			{
				if (ubah[s[j] - '0'] < s[j] - '0')
				{
					goto hell;
				}
				// cout << j << " " << s[j] << endl;
				// cout << j << " ";
				// cout << endl;
				s[j] = ubah[s[j] - '0'] + '0';
			}
			break;
		}
	}
	hell:;
	cout << s << endl;
}