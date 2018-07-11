#include <bits/stdc++.h>
using namespace std;

int tab[200010];

int main()
{
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	int n=s.length();
	for (int i=0;i<n;i++)
	 {
	 	tab[i]=s[i]-'0';
	 	tab[i]%=3;
	 }
	int now=0;
	int ans=0;
	int i=0;
	tab[n]=-1;
	while (i<n)
	{
		if (tab[i]==0)
		{
			++ans;
			++i;
		}
		else
		if (tab[i]==1)
		{
			if (tab[i+1]==1)
			{
				if (tab[i+2]==1)
				{
					++ans;
					i+=3;
				}
				else
				 ++i;
			}
			else
			if (tab[i+1]==2)
			{
				++ans;
				i+=2;
			}
			else
			 ++i;
		}
		else
		if (tab[i]==2)
		{
			if (tab[i+1]==2)
			{
				if (tab[i+2]==2)
				{
					++ans;
					i+=3;
				}
				else
				 ++i;
			}
			else
			if (tab[i+1]==1)
			{
				++ans;
				i+=2;
			}
			else
			 ++i;
		}
	}
	cout<<ans<<"\n";
}