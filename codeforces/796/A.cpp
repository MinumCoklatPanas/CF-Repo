#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int i,j,k,n,m,tab[110],min,jar;
	cin>>n>>m>>k;
	bool b=true;
	for (i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	if ((tab[i]<=k)&&(tab[i]!=0))
	 	{
	 		jar=abs(i-m);
	 		//cout<<jar<<" jar\n";
	 		if (b)
	 		{
	 			b=false;
	 			min=jar;
			 }
			else
			 if (jar<min)
			  min=jar;
		 }
	 }
	 int hasil=min*10;
	 cout<<hasil<<"\n";
}
