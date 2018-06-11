#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gud;
ll tab[2][300010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		mx=max(mx,(int)s.length());
		stack<char> st;
		for (int j=0;j<s.length();j++)
		{
			if (!st.empty())
			{
				if (s[j]==')' && st.top()=='(')
				 st.pop();
				else
				 if (s[j]=='(' && st.top()==')')
				 {
				 	st.push(s[j]);
				 }
				else
				 st.push(s[j]);
			}
			else
			 st.push(s[j]);
		}
		if (st.empty())
		{
			++gud;
			continue;
		}
//		cout<<i<<" "<<st.size()<<
		int siz=st.size();
		char now=st.top();
		bool beda=false;
		while (!st.empty())
		{
			if (st.top()!=now)
			 beda=true;
			st.pop();
		}
		if (!beda)
		{
			if (now=='(')
			 tab[0][siz]++;
			else
			 tab[1][siz]++;
		}
	}
	ll ans=gud*gud;
	for (int i=1;i<=mx;i++)
	 {
//	 	cout<<tab[0][i]<<" "<<tab[1][i]<<"\n";
	 	ans+=tab[0][i]*tab[1][i];
	 }
	cout<<ans<<"\n";
}
