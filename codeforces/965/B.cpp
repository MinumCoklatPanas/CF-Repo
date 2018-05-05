#include <bits/stdc++.h>
using namespace std;

char tab[110][110];
int res[110][110];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt","r",stdin);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	  cin>>tab[i][j];
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	 {
	 	if (tab[i][j]=='#') continue;
//	 	cout<<i<<" "<<j<<"\n";
	 	//cek bawah
	 	for (int l=0;l<k;l++)
	 	{
	 		int x,y;
	 		x=i;
	 		y=j-l;
	 		if (y<1) break;
	 		bool bisa=true;
	 		for (int m=y;m<y+k;m++)
	 		{
	 			if (m>n)
	 			{
	 				bisa=false;
	 				break;
				}
	 			if (tab[x][m]=='#')
	 			{
	 				bisa=false;
	 				break;
				}
			}
//			cout<<l<<" "<<bisa<<" l bisa\n";
			res[i][j]+=bisa;
		}
//		if (i==6 && j==1)
//		cout<<res[i][j]<<" bawah\n";
		//cek kanan
		for (int l=0;l<k;l++)
	 	{
	 		int x,y;
	 		x=i-l;
	 		y=j;
	 		if (x<1) break;
	 		bool bisa=true;
	 		for (int m=x;m<x+k;m++)
	 		{
//	 			if (i==9 && j==1)
//	 			 cout<<x<<" "<<m<<" "<<y<<" my\n";
	 			if (m>n)
	 			{
//	 				if (i==9 && j==1)
//	 				cout<<"yo\n";
	 				bisa=false;
	 				break;
				}
	 			if (tab[m][y]=='#')
	 			{
//	 				if (i==9 && j==1)
//	 				cout<<"yo\n";
	 				bisa=false;
	 				break;
				}
			}
			res[i][j]+=bisa;
		}
//		if (i==6 && j==1)
//		cout<<res[i][j]<<" kanan\n";
	 }
//	for (int i=1;i<=n;i++)
//	 for (int j=1;j<=n;j++)
//	 {
//	 	if (j==n)
//	 	 cout<<res[i][j]<<"\n";
//	 	else
//	 	 cout<<res[i][j]<<" ";
//	 }
	int ansX=1,ansY=1;
	int mx=0;
	for (int i=1;i<=n;i++)
	 for (int j=1;j<=n;j++)
	 {
	 	if (res[i][j]>mx)
	 	{
	 		mx=res[i][j];
	 		ansX=i;
	 		ansY=j;
		}
	 }
	cout<<ansX<<" "<<ansY<<"\n";
}
