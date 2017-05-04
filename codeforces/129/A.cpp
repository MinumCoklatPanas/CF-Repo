#include <iostream>
using namespace std;

int main ()
{
	int n,sum,ganjil,genap,tab[110];
	cin>>n;
	sum=0;
	ganjil=0;
	genap=0;
	for (int i=1;i<=n;i++)
	 {
	 	cin>>tab[i];
	 	sum+=tab[i];
	 	if (tab[i]%2==1)
	 	 ganjil++;
	 	else 
	 	genap++;
	 }
	if (sum%2==0)
	 cout<<genap<<"\n";
	else
	 {
	 	if (ganjil%2==1)
	 	 cout<<ganjil<<"\n";
	 	else
	 	 cout<<ganjil-1<<"\n";
	 }
	 return 0;
}
