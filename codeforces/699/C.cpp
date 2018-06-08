#include <bits/stdc++.h>
using namespace std;

int tab[110];
bool bisa[2][110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++)
	 cin>>tab[i];
	bisa[0][0]=1;
	bisa[1][0]=1;
	for (int i=1;i<=n;i++)
	{
		if (tab[i]==0)
		{
			bisa[0][i]=bisa[1][i]=0;
		}
		else
		if (tab[i]==1)
		{
			bisa[0][i]=0;
			if (bisa[0][i-1] ||!bisa[1][i-1])
			 bisa[1][i]=1;
		}
		else
		if (tab[i]==2)
		{
			bisa[1][i]=0;
			if (bisa[1][i-1] || !bisa[0][i-1])
			 bisa[0][i]=1;
		}
		else
		if (tab[i]==3)
		{
			if (bisa[0][i-1] || !bisa[1][i-1])
			 bisa[1][i]=1;
			if (bisa[1][i-1] || !bisa[0][i-1])
			 bisa[0][i]=1;
		}
		ans+=(!bisa[0][i] && !bisa[1][i]);
//		cout<<i<<" "<<bisa[0][i]<<" "<<bisa[1][i]<<" "<<ans<<"\n";
	}
//	for (int i=1;i<=n;i++)
//	 cout<<bisa[0][i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)
//	 cout<<bisa[1][i]<<" ";
//	cout<<"\n";
	cout<<ans<<"\n";
}
