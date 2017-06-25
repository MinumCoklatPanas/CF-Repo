#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i,j,k,n,tab[55][55],l;
	cin>>n;
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	  cin>>tab[i][j];
	for (i=1;i<=n;i++)
	 for (j=1;j<=n;j++)
	  {
	  	bool cek=false;
	  	bool cek1=false;
	  	if (tab[i][j]!=1){
	  	//cout<<i<<" "<<j<<" ij\n";
	  	//cout<<tab[i][j]<<"\n";
	  	for (k=1;k<=n;k++)
	  	{
	  		if (k!=j)
	  		{
	  			//cout<<i<<" "<<k<<" i k\n";
	  			//cout<<tab[i][k]<<"\n";
	  			int sum=tab[i][j];
	  			if (tab[i][k]<tab[i][j])
	  			{	
	  				bool cek2=false;
	  				sum=tab[i][k];
	  				//cout<<sum<<" sum\n";
	  				for (l=1;l<=n;l++)
	  				 {
	  				 	//cout<<l<<" l\n";
	  				 	//cout<<l<<" "<<j<<" lj\n";
	  				 	//cout<<sum<<"\n";
	  				 	//cout<<tab[l][j]<<"\n";
	  				 	if (l==i)
	  				 	 continue;
	  				 	else
	  				 	 {
	  				 	 	if (sum+tab[l][j]==tab[i][j])
	  				 	 	{
	  				 	 		//cout<<"yo\n";
	  				 	 		cek2=true;
	  				 	 		break;
							}
						 }
					 }
					 //cout<<cek2<<"\n";
					 //
					if (cek2)
					 {
					 	//cout<<"yo\n";
					 	cek1=true;
					 	break;
					 }
				}
			}
		}
		if (cek1)
		{
			cek=true;
		}
		if (!cek)
		{
			cout<<"No\n";
			return 0;
		}
		}
	  }
	cout<<"Yes\n";
	return 0;
}
