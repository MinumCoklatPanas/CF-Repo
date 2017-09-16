#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt","r",stdin);
	ll i,j,k,n,tab[310][310];
	cin>>n;
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	  cin>>tab[i][j];
	bool cek[310][310];
	memset(cek,0,sizeof(cek));
	ll sum=0;
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	 {
	 	if (i==j) continue;
	 	if (cek[i][j]) continue;
	 	//cout<<i<<" "<<j<<" ij\n";
	 	//sum+=tab[i][j];
	 	//cek[i][j]=1;
	 	cek[j][i]=1;
	 	bool ada=true;
	 	for (k=1;k<=n;k++)
	 	{
	 		if (k==j) continue;
	 		if (k==i) continue;
	 		if (tab[k][j]+tab[k][i]==tab[i][j])
	 		{
	 			//cout<<k<<" "<<i<<" "<<j<<" masuk\n";
	 			if (!cek[k][j] && !cek[j][k])
	 			 cek[k][j]=1;
	 			if (!cek[k][i] && !cek[i][k])
	 			 cek[k][i]=1;
	 			cek[i][j]=1;
	 			ada=false;
			}
			if (tab[k][j]+tab[k][i]<tab[i][j])
			{
				cout<<-1<<"\n";
				return 0;
			}
		}
	 }
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	  if (!cek[i][j])
	   {
	   		sum+=tab[i][j];
	   		//cout<<i<<" "<<j<<" tambah\n";
	   }
	cout<<sum<<"\n";
}