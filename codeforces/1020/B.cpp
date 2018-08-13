#include <bits/stdc++.h>
using namespace std;

bool sudah[1010];
int tab[1010];
int ans[1010];

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	for (int i=1;i<=n;i++)
	{
		memset(sudah,0,sizeof(sudah));
		sudah[i]=1;
//		int ans=-1;
		int now=i;
		while (!sudah[tab[now]])
		{
			sudah[tab[now]]=1;
			now=tab[now];
		}
		ans[i]=tab[now];
	}
	for (int i=1;i<=n;i++)
	{
		if (i==n)
		 cout<<ans[i]<<"\n";
		else
		 cout<<ans[i]<<" ";
	}
	cout<<"\n";
}