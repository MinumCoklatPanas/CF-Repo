#include <bits/stdc++.h>
using namespace std;

char tab[510][510];
int n,m;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 cin>>tab[i][j];
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (tab[i][j]=='S')
	 	{
	 		for (int k=0;k<4;k++)
	 		{
	 			int ii=i+dx[k];
	 			int jj=j+dy[k];
	 			if (1<=ii && ii<=n && 1<=jj && jj<=m && tab[ii][jj]=='.')
	 			 tab[ii][jj]='D';
			}
		}
	 }
//		for (int i=1;i<=n;i++)
//	 for (int j=1;j<=m;j++)
//	 {
//	 	if (j==m)
//	 	 cout<<tab[i][j]<<"\n";
//	 	else
//	 	 cout<<tab[i][j]<<" ";
//	 }
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (tab[i][j]=='S')
	 	{
	 		for (int k=0;k<4;k++)
	 		{
	 			int ii=i+dx[k];
	 			int jj=j+dy[k];
//	 			cout<<i<<" "<<j<<" "<<ii<<" "<<jj<<'\n';
	 			if (1<=ii && ii<=n && 1<=jj && jj<=m && tab[ii][jj]=='W')
	 			{
	 				cout<<"No\n";
	 				return 0;
				 }
			 }
		 }
	 }
	cout<<"Yes\n";
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if (j==m)
	 	 cout<<tab[i][j]<<"\n";
	 	else
	 	 cout<<tab[i][j];
	 }
}
