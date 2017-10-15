#include <bits/stdc++.h>
using namespace std;

int n,m;

bool betweenR(int x)
{
	return (1<=x && x<=n); 
}

bool betweenC(int x)
{
	return (1<=x && x<=m);
}

int main()
{
	cin>>n>>m;
	char tab[55][55];
	int ans[55][55];
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	  {
	  	cin>>tab[i][j];
	  	if (tab[i][j]=='#') ans[i][j]=-1;
	  } 
	int delta[3]={-1,0,1};
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (tab[i][j]!='#') continue;
		for (int k=0;k<3;k++)
		 for (int l=0;l<3;l++)
		 {
		 	if (delta[l]==0 && delta[k]==0) continue;
		 	int x=i+delta[k];
		 	int y=j+delta[l];
		 	if (tab[x][y]=='#') continue;
		 	if (!betweenR(x)) continue;
		 	if (!betweenC(y)) continue;
		 	ans[x][y]++;
		 }
	 }
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (j==m)
	 	{
	 		if (ans[i][j]==-1)
	 		 cout<<"#\n";
	 		else
	 		 cout<<ans[i][j]<<"\n";
		}
		else
		 {
		 	if (ans[i][j]==-1)
		 	 cout<<"#";
		 	else
		 	 cout<<ans[i][j];
		 }
	 }
}