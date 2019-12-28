#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double INFD = 1E9;
const double EPS = 1e-9;

bool ada[200010];
bool hilang[200010];
int tab[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> tab[i];
		ada[tab[i]] = 1;
	}
	deque< int > dq;
	for (int i = 1 ; i <= n ; i++) if (!ada[i])
	{	
		dq.push_back(i);
		hilang[i] = 1;
	}
	for (int i = 1 ; i <= n ; i++) if (hilang[i] && !tab[i])
	{
		if (dq.front() != i)
		{
			tab[i] = dq.front();
			dq.pop_front();
		}
		else
		{
			tab[i] = dq.back();
			dq.pop_back();
		}
		assert(i != tab[i]);
	}
	for (int i = 1 ; i <= n ; i++) if (!tab[i])
	{
		// assert(tab[i] != dq.front());
		tab[i] = dq.front();
		assert(i != tab[i]);
		dq.pop_front();
	}
	for (int i = 1 ; i <= n ; i++)
	{
		if (i == n)
			cout << tab[i] << endl;
		else
			cout << tab[i] << " ";
	}
}