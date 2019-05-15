#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll INFF = 1e18;
const int MAXN = 510;
const int MOD = 1e9 + 7;

bool state[200010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<char> R,B;
	int depthR = 0,depthB = 0;
	string s;
	int n;
	cin >> n >> s;
	for (int i = 0 ; i < s.length() ; i++)
	{
		// cout << i << endl;
		// cout << R.size() << " " << B.size() << endl;
		if (s[i] == '(')
		{
			if (R.size() == B.size())
			{
				if (depthR < depthB)
				{
					R.push(s[i]);
					state[i] = 0;
				}
				else
				{
					B.push(s[i]);
					state[i] = 1;
				}
			}
			else
			if (R.size() < B.size())
			{
				R.push(s[i]);
				state[i] = 0;	
			}
			else
			{
				B.push(s[i]);
				state[i] = 1;
			}
		}
		else
		{
			if (R.empty())
			{
				assert(!B.empty());
				depthB = max(depthB,(int)B.size());
				B.pop();
				state[i] = 1;
			}
			else
			if (B.empty())
			{
				assert(!R.empty());
				depthR = max(depthR,(int)R.size());
				R.pop();
				state[i] = 0;
			}
			else
			{
				if (R.size() < B.size())
				{
					depthR = max(depthR,(int)R.size());
					R.pop();
					state[i] = 0;
				}
				else
				{
					depthB = max(depthB,(int)B.size());
					B.pop();	
					state[i] = 1;
				}
			}
		}
		// cout << R.size() << " " << B.size() << endl;
	}
	for (int i = 0 ; i < n ; i++)
	{
		if (i == n - 1)
			cout << state[i] << endl;
		else
			cout << state[i];
	}	
}