#include <bits/stdc++.h>
using namespace std;

int tab[100010];
bool ya[100010];

int main()
{
//	freopen("input.txt","r",stdin);
	string s;
	cin>>s;
	int satu=0;
	for (int i=0;i<s.length();i++)
	{
		tab[i]=s[i]-'0';
		satu+=(tab[i]==1);
	}
	int n=s.length();
	int nol;
	int i=0;
	bool sudah=false;
	int cnt=0;
	while (i<n)
	{
		cnt+=(tab[i]==0);
		ya[i]=(tab[i]==0);
		if (tab[i]==2) break;
		++i;
	}
	for (int i=1;i<=cnt;i++)
	 cout<<0;
	for (int i=1;i<=satu;i++)
	 cout<<1;
	for (int i=0;i<n;i++)
	{
		if (ya[i] || tab[i]==1) continue;
		cout<<tab[i];
	}
	cout<<"\n";
}