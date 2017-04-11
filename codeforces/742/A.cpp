#include <algorithm>
#include <iostream>
using namespace std;

int main ()
{
	int n,tab[10];
	tab[0]=6;
	tab[1]=8;
	tab[2]=4;
	tab[3]=2;
	cin>>n;
	int a= n%4;
	if (n==0)
	 tab[a]=1;
	cout<<tab[a]<<"\n";
}
