#include <iostream>
using namespace std;

int main()
{
	int a,b,c,tab[10];
	for (a=1;a<=3;a++)
	{
		cin>>b;
		tab[b]++;
	}
	if (tab[5]==2 && tab[7]==1)
	 cout<<"YES\n";
	else
	 cout<<"NO\n";
}
