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

bool cek(string s,int pos)
{
	int n = s.length();
	int x = n - 1 - pos;
	for (int i = 0 ; i <= pos ; i++)
	{
		if (s[i] != s[x]) return false;
		++x;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	string tambah;
	for (int i = n - 2 ; i >= 0 ; i--)
	{
		if (cek(s,i))
		{
			// cout << i << endl;
			for (int j = i + 1 ; j < n ; j++)
				tambah += s[j];
			break;
		}
	}
	if (tambah == "")
		tambah = s;
	for (int i = 1 ; i < k ; i++)
		s += tambah;
	cout << s << endl;
	return 0;
}