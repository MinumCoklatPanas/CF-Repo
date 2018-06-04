#include <bits/stdc++.h>
using namespace std;

string s;
vector< pair<char,int> > tab;

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>s;
	int i=0;
	while (i<s.length())
	{
		char now=s[i];
		int cnt=0;
		while (s[i]==now)
		{
			++i;
			++cnt;
		}
		tab.push_back({now,cnt});
	}
//	for (int i=0;i<tab.size();i++)
//	 cout<<tab[i].first<<" "<<tab[i].second<<"\n";
	for (int i=0;i<tab.size();i++)
	{
		if (tab[i].second==1) continue;
		if (i==tab.size()-1)
		{
			tab[i].second=2;
			continue;
		}
		tab[i].second=2;
		tab[i+1].second=1;
	}
	for (int i=0;i<tab.size();i++)
	{
		for (int j=1;j<=tab[i].second;j++)
		 cout<<tab[i].first;
	}
	cout<<"\n";
}
