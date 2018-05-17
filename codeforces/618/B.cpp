#include <bits/stdc++.h>
using namespace std;

int tab[55][55];

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  cin>>tab[i][j];
	for (int i=1;i<=n;i++)
	 {
	 	set<int> isi;
	 	for (int j=1;j<=n;j++)
	 	 isi.insert(tab[i][j]);
	 	if (isi.size()==n)
	 	{
	 		for (int j=1;j<=n;j++)
	 		{
	 			if (tab[i][j]==0)
	 			 cout<<n;
	 			else
	 			 cout<<tab[i][j];
	 			if (j==n)
	 			 cout<<"\n";
	 			else
	 			 cout<<" ";
			}
			return 0;
		}
	 }
}
