#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for (int i=1;i<=m;i++)
	{
		int a,b;
		char x,y;
		cin>>a>>b>>x>>y;
		--a; --b;
		for (int j=a;j<=b;j++)
		{
			if (s[j]==x)
			 s[j]=y;
		}
	}
	cout<<s<<"\n";
}
