#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for (int i=0;i<n-1;i++)
	{
		if (s[i]!='?' && s[i+1]==s[i])
		{
			cout<<"No\n";
			return 0;
		}
	}
	for (int i=0;i<n-1;i++)
	{
		if (s[i]=='?' && s[i]==s[i+1])
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	if (s[0]=='?' || s[n-1]=='?')
	{
		cout<<"Yes\n";
		return 0;
	}
	for (int i=1;i<n-1;i++)
	{
		if (s[i]=='?' && s[i-1]==s[i+1])
		{
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}
