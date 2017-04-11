#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

int tab[1000010]{};
 
int main ()
{
	int n,m,k,j,i,q;
	int x=1;
	tab[1]=1;
	scanf("%d %d %d",&n,&m,&k);
	for (i=1;i<=m;i++)
	{
		//cout<<"halo\n";
		scanf("%d",&q);
		tab[q]=2;
	}
	int a,b;
	bool bo=true,bo2=true;
	for (i=1;i<=k;i++)
	{
		scanf("%d %d",&a,&b);
		//cout<<tab[a]<<" "<<tab[b]<<"\n";
		//cout<<"bo sekarang "<<bo<<"\n";
		if ((tab[b]==2)&&(tab[a]==1))
		{
			if (bo2){
			//cout<<"yo\n";
			bo=false;
			x=b;
			bo2=false;
		}
		}
		else
		 if ((tab[a]==2)&&(tab[b]==1))
		 {
		 	if (bo2){
		 		bo=false;
		 		x=a;
		 		bo2=false;
			 }
		 }
		else
		 {
		 	if (bo)
		 	 {
		 	 	if ((tab[a]==2)||(tab[b]==2))
		 	 	 {
				   if ((tab[a]!=0)&&(tab[b]!=0))
				    swap(tab[a],tab[b]);
				   }
				else
		 	 	swap(tab[a],tab[b]);
		 	 	if (tab[b]==1)
		 	 	 x=b;
		 	 	else
		 	 	 if (tab[a]==1)
		 	 	  x=a;
			  }
		 }
		 //cout<<"bo sekarang "<<bo<<"\n";
		 //cout<<"x sekarang "<<x<<"\n";
		
	}

	printf("%d\n",x);
}
