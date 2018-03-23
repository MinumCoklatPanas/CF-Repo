#include <bits/stdc++.h>
using namespace std;

int frek[30];

int main()
{
	string s;
	cin>>s;
	set<int> huruf;
	for (int i=0;i<s.length();i++)
	{
		int ix=s[i]-'a'+1;
		frek[ix]++;
		huruf.insert(ix);
	}
	if (huruf.size()==2)
	{
		for (set<int>::iterator it=huruf.begin();it!=huruf.end();++it)
		{
			if (frek[*it]==1)
			{
				cout<<"No\n";
				return 0;
			}
		}
		cout<<"Yes\n";
		return 0;
	}
	if (huruf.size()==3)
	{
		for (set<int>::iterator it=huruf.begin();it!=huruf.end();++it)
		{
			if (frek[*it]>=2)
			{
				cout<<"Yes\n";
				return 0;
			}
		}
		cout<<"No\n";
		return 0;
	}
	if (huruf.size()==4)
	{
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No\n";
}
