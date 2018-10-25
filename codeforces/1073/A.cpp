#include <bits/stdc++.h>
using namespace std;

int frek[30][1010];
char tab[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		 {
		 	cin>>tab[i];
		 	for (int j=1;j<=26;j++)
		 		 frek[j][i]=frek[j][i-1];
		 	frek[tab[i]-'a'+1][i]++;
		 }
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n-i+1;j++)
		{
			int kiri=j;
			int kanan=j+i-1;
			bool yes=1;
			for (int k=1;k<=26;k++)
			{
				int sum=frek[k][kanan]-frek[k][kiri-1];
				if (2*sum>i)
				{
					yes=false;
					break;
				}
			}
			if (yes)
			{
				cout<<"YES\n";
				for (int k=kiri;k<=kanan;k++)
					 cout<<tab[k];
				cout<<"\n";
				return 0;
			}
		}
	}
	cout<<"NO\n";
}