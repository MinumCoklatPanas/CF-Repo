#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if (n==1)
	{
		if (s[0]=='1')
		 cout<<"Yes\n";
		else
		 cout<<"No\n";
		return 0;
	}
	for (int i=0;i<n;i++)
	{
		if (s[i]=='1')
		{
			if (i>0 && i<s.length()-1)
			{
				if (s[i-1]!='0' || s[i+1]!='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
			else
			if (i==0)
			{
				if (s[i+1]!='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
			else
			{
				if (s[i-1]!='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
		}
		else
		{
			if (i>0 && i<s.length()-1)
			{
				if (s[i-1]=='0' && s[i+1]=='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
			else
			if (i==0)
			{
				if (s[i+1]=='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
			else
			{
				if (s[i-1]=='0')
				{
					cout<<"No\n";
					return 0;
				}
			}
		}
	}
	cout<<"Yes\n";
}
