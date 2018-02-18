#include <bits/stdc++.h>
using namespace std;

int tab[5][5];

int main()
{
	for (int i=1;i<=3;i++)
	 for (int j=1;j<=3;j++)
	  cin>>tab[i][j];
	for (int i=1;i<3;i++)
	 for (int j=i+1;j<=3;j++)
	 {
	 	int now=tab[1][i]-tab[1][j];
	 	for (int k=2;k<=3;k++)
	 	{
	 		int diff=tab[k][i]-tab[k][j];
	 		if (diff!=now)
	 		{
	 			cout<<"No\n";
	 			return 0;
			 }
		 }
	 }
	cout<<"Yes\n";
}