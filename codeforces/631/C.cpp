#include <bits/stdc++.h>
using namespace std;

int ans[200010];
int tab[200010];
int last[200010];
int ix[200010];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	int mx=0;
	for (int i=1;i<=m;i++)
	{
		int ask,a;
		cin>>ask>>a;
		last[a]=ask;
		ix[a]=i;
		mx=max(mx,a);
	}
	for (int i=mx;i>=1;i--)
	 if (!last[i] || ix[i]<ix[i+1])
	  {
	  	last[i]=last[i+1];
	  	ix[i]=ix[i+1];
	  }
//	for (int i=1;i<=mx;i++)
//	 cout<<ix[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=mx;i++)
//	 cout<<last[i]<<" ";
//	cout<<"\n";
	for (int i=mx+1;i<=n;i++)
	 ans[i]=tab[i];
	if (last[mx]==2)
	 sort(tab+1,tab+mx+1,cmp);
	else
	 sort(tab+1,tab+mx+1);
	ans[mx]=tab[mx];
	int kiri=1;
	int kanan=mx-1;
	for (int i=mx-1;i>=1;i--)
	{
		if (last[i]==last[mx])
		{
			ans[i]=tab[kanan--];
		}
		else
		{
			ans[i]=tab[kiri++];
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (i==n)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
}
