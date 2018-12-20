#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		set<char> st;
		string s;
		cin>>s;
		for (int i=0;i<s.length();i++)
			st.insert(s[i]);
		if (st.size()==1)
		{
			cout<<-1<<"\n";
			continue;
		}
		string tmp=s;
		sort(tmp.begin(),tmp.end());
			cout<<tmp<<"\n";
	}
}