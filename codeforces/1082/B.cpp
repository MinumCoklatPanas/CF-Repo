#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector< pair<char,int> > partisi;
	int i=0;
	int G=0;
	int S=0;
	while (i<s.length())
	{
		char now=s[i];
		int cnt=0;
		while (s[i]==now && i<s.length())
		{
			++cnt;
			++i;
		}
		partisi.push_back(make_pair(now,cnt));
		if (now=='S')
			++S;
		else
			++G;
	}
	int ans=0;
	for (int i=0;i<partisi.size();i++)
	{
		if (G==1 && partisi[i].first=='G')
		{
			cout<<partisi[i].second<<"\n";
			return 0;
		}
		if (partisi[i].first=='S')
		{
			if (i==0)
			{
				if (G==1)
					ans=max(ans,partisi[i+1].second);
				else
				if (G>1)
					ans=max(ans,partisi[i+1].second+1);
			}
			else
			if (i==partisi.size()-1)
			{
				if (G==1)
					ans=max(ans,partisi[i-1].second);
				else
				if (G>1)
					ans=max(ans,partisi[i-1].second+1);
			}
			else
			if (partisi[i].second==1)
			{
				// cout<<"yo\n";
				if (G>2)
					ans=max(ans,partisi[i-1].second+partisi[i+1].second+1);
				else
				{
					assert(G==2);
					ans=max(ans,partisi[i-1].second+partisi[i+1].second);
				}
			}
			else
			if (partisi[i].second>1)
			{
				if (G>=2)
					ans=max(ans,max(partisi[i-1].second+1,partisi[i+1].second+1));
			}
		}
	}
	cout<<ans<<"\n";
}