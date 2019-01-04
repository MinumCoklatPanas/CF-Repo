#include <bits/stdc++.h>
using namespace std;

map<int,int> frek;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int mx = 0;
	frek.clear();
	for (int i = 1 ; i <= n ; i++)
	{
		string s;
		cin >> s;
		stack< char > st;
		for (int j = 0 ; j < s.length() ; j++)
		{
			if (st.empty())
			{
				st.push(s[j]);
			}
			else
			{
				if (st.top() == '(' && s[j] == ')')
					st.pop();
				else
					st.push(s[j]);
			}
		}
		if (st.empty())
		{
			frek[0]++;
			continue;
		}
		int val = 0;
		char atas = st.top();
		bool bisa = 1;
		while (!st.empty())
		{
			if (st.top() != atas)
			{
				bisa = 0;
				break;
			}
			if (atas == '(')
				--val;
			else
				++val;
			st.pop();
		}
		// cout << i << "  " val << endl;
		if (bisa)
		frek[val]++;
		mx = max(mx,val);
	}
	int ans = 0;
	for (int i = 1 ; i <= mx ; i++)
	{
		ans += min(frek[i],frek[-1 * i]);
	}
	ans += frek[0] / 2;
	cout << ans << endl;
}