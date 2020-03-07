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
	string s;
	cin >> s;
	deque< char > dq;
	for (int i = 0 ; i < s.length() ; i++)
		dq.push_back(s[i]);
	int q;
	cin >> q;
	int curState = 0;
	while (q--)
	{
		int ask;
		cin >> ask;
		if (ask == 1)
			curState ^= 1;
		else
		{
			int x;
			cin >> x;
			--x;
			x ^= curState;
			char ta;
			cin >> ta;
			if (x == 0)
				dq.push_front(ta);
			else
				dq.push_back(ta);
		}
	}
	if (curState)
		reverse(dq.begin(),dq.end());
	for (auto i : dq)
		cout << i;
	cout << endl;
	return 0;
}