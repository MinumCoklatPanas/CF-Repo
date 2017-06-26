#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,n,m;
	char tab[1010][1010];
	cin>>n>>m;
	for (i=0;i<=n+1;i++)
	{
		
		tab[i][0]='#';
		tab[i][m+1]='#';
	}
	for (i=0;i<=m+1;i++)
	{
		
		tab[0][i]='#';
		tab[n+1][i]='#';
	}
	for (i=1;i<=n;i++)
	 for (j=1;j<=m;j++)
	  cin>>tab[i][j];
	for (i=0;i<=n+1;i++)
	 for (j=0;j<=m+1;j++)
	  {
	  	if (j==m+1)
	  	 cout<<tab[i][j]<<"\n";
	  	else
	  	 cout<<tab[i][j];
	  }
	return 0;
}