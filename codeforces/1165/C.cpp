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
	string s;
	cin >> s;
	deque<char> ans;
	bool state = 1;
	for (int i = 0 ; i < n ; i++)
	{
		// cout << i << " " << state << endl;
		if (state)
		{
			ans.push_back(s[i]);
			state ^= 1;
		}
		else
		{
			if (s[i] != ans.back())
			{
				// cout << i << endl;
				ans.push_back(s[i]);
				state ^= 1;
			}
		}
	}
	if (ans.size() % 2 == 1)
		ans.pop_back();
	cout << n - ans.size() << endl;
	for (int i = 0 ; i < ans.size() ; i++)
		cout << ans[i];
	cout << endl;
}