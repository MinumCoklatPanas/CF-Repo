#include <bits/stdc++.h>
using namespace std;

char tab[1010][1010];
int row[1010];
int col[1010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	int tot=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	cin>>tab[i][j];
	 	tot+=(tab[i][j]=='*');
	 }
	if (!tot)
	{
		cout<<"YES\n";
		cout<<1<<" "<<1<<"\n";
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		int res=(tab[i][1]=='*');
		for (int j=2;j<=m;j++)
		 res+=(tab[i][j]=='*');
		row[i]=res;
	}
	for (int i=1;i<=m;i++)
	{
		int res=(tab[1][i]=='*');
		for (int j=2;j<=n;j++)
		 res+=(tab[j][i]=='*');
		col[i]=res;
	}
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=m;j++)
	 {
	 	if ((row[i]+col[j]-1==tot && tab[i][j]=='*') || (row[i]+col[j]==tot && tab[i][j]=='.'))
	 	{
	 		cout<<"YES\n";
	 		cout<<i<<" "<<j<<"\n";
	 		return 0;
		 }
	 }
	cout<<"NO\n";
}
