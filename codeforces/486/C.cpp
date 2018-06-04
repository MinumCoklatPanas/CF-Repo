#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n,p;
	cin>>n>>p;
	--p;
	--n;
	string s;
	cin>>s;
	if (2*p>=n)
	{
		p=n-p;
		reverse(s.begin(),s.end());
	}
	int r=-1;
	for (int i=(n/2);i>=p;i--)
	{
		if (s[i]!=s[n-i])
		{
			r=i;
			break;
		}
	}
	int l=-1;
	for (int i=0;i<p;i++)
	{
		if (s[i]!=s[n-i])
		{
			l=i;
			break;
		}
	}
	int ans=0;
	if (l==-1 && r==-1)
	{
		ans=0;
	}
	else
	if (l==-1)
	{
		for (int i=p;i<=r;i++)
		{
			if (s[i]!=s[n-i])
			{
				int diff=abs(s[i]-s[n-i]);
				if (diff>13)
				 diff=26-diff;
				ans+=diff;
			}
			++ans;
		}
		--ans;
	}
	else
	if (r==-1)
	{
		for (int i=p;i>=l;i--)
		{
			if (s[i]!=s[n-i])
			{
				int diff=abs(s[i]-s[n-i]);
				if (diff>13)
				 diff=26-diff;
				ans+=diff;
			}
			++ans;
		}
		--ans;
	}
	else
	{
//		--n;
		string s1=s;
		string s2=s;
		int ans1=0,ans2=0;
		for (int i=p;i<=r;i++)
		{
			if (s1[i]!=s1[n-i])
			{
				int diff=abs(s1[i]-s1[n-i]);
				if (diff>13)
				 diff=26-diff;
				ans1+=diff;
				s1[i]=s1[n-i];
			}
			++ans1;
		}
		--ans1;
		
		for (int i=r;i>=l;i--)
		{
			if (s1[i]!=s1[n-i])
			{
				int diff=abs(s1[i]-s1[n-i]);
				if (diff>13)
				 diff=26-diff;
				ans1+=diff;
				s1[i]=s1[n-i];
			}
			++ans1;
		}
		
		--ans1;
				
		//ans2
		
		for (int i=p;i>=l;i--)
		{
			if (s2[i]!=s2[n-i])
			{
				int diff=abs(s2[i]-s2[n-i]);
				if (diff>13)
				 diff=26-diff;
				ans2+=diff;
				s2[i]=s2[n-i];
			}
			++ans2;
		}
		
		
		--ans2;
		
		for (int i=l;i<=r;i++)
		{
			if (s2[i]!=s2[n-i])
			{
				int diff=abs(s2[i]-s2[n-i]);
				if (diff>13)
				 diff=26-diff;
				ans2+=diff;
				s2[i]=s2[n-i];
			}
			++ans2;
		}
		
		--ans2;
				
		ans=min(ans1,ans2);
	}
	cout<<ans<<"\n";
}
