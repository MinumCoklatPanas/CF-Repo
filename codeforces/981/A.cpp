#include <bits/stdc++.h>
using namespace std;

bool pal(string s)
{
	int l=0;
	int r=s.length()-1;
	while (l<r)
	{
		if (s[l]!=s[r]) return false;
		++l;
		--r;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	int ans=0;
	for (int i=0;i<s.length();i++)
	{
		string tmp;
		tmp="";
		for (int j=i;j<s.length();j++)
		{
			tmp="";
			for (int k=i;k<=j;k++)
			 tmp+=s[k];
			// cout<<tmp<<"\n";
			if (!pal(tmp))
			{
				// cout<<tmp<<" ya\n";
				ans=max(ans,j-i+1);
			}
		}
	}
	cout<<ans<<"\n";
}
