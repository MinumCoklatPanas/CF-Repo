#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	if (s.length()<26)
	{
		cout<<-1<<"\n";
		return 0;
	}
	char cari='a';
	for (int i=0;i<s.length();i++)
	{
		if (cari>'z') break;
		if (s[i]<=cari)
		{
			s[i]=cari;
			++cari;
		}
	}
	if (cari<='z')
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<s<<"\n";
}
