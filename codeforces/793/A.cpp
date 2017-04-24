#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	
	 long long i,j,k,n,sum,beda,tab[100010];
	 cin>>n>>k;
	 for (i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 }
	 sort(tab+1,tab+n+1);
	 bool b=true;
	 sum=0;
	 for (i=2;i<=n;i++)
	 {
	 	beda=tab[i]-tab[1];
	 	if (beda%k!=0)
	 	{
	 		b=false;
	 		break;
		 }
		else
		 {
		 	beda=beda/k;
		 	sum+=beda;
		 }
	 }
	 if (not b)
	  cout<<-1<<"\n";
	else
	 cout<<sum<<"\n";
}
