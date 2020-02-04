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

vector< int > adj[210];
int color[210];

bool cek(int u)
{
	bool res = true;
	for (int next : adj[u])
	{
		if (color[next] == -1)
		{
			color[next] = color[u] ^ 1;
			res &= cek(next);
		}
		else
		if (color[next] == color[u]) return false;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0 ; i < s.length() ; i++)
	{
		for (int j = 0 ; j < i ; j++) if (s[j] > s[i])
		{
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	bool ans = 1;
	memset(color,-1,sizeof(color));
	for (int i = 0 ; i < n ; i++) if (color[i] == -1)
	{
		color[i] = 0;
		ans &= cek(i);
	}
	if (!ans)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 0 ; i < n ; i++)
			cout << color[i];
		cout << endl;
	}
	return 0;
}