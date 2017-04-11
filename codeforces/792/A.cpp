#include <iostream>
#include <algorithm>
using namespace std;

int tab[200010];

int main ()
{
	int n,i,j;
	cin>>n;
	for (i=1;i<=n;i++)
	 cin>>tab[i];
	sort(tab+1,tab+n+1);
	int min=tab[2]-tab[1],x=1,m;
	for (i=2;i<n;i++)
	{
		m=tab[i+1]-tab[i];
		if (m==min)
		 x++;
		else
		 if (m<min)
		 {
		 	min=m;
		 	x=1;
		 }
	}
	cout<<min<<" "<<x<<"\n";
}
